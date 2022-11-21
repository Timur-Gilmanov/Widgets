#ifndef BOX_HPP_
#define BOX_HPP_

#include <memory>
#include <string>
#include <vector>
#include "abstract_widgets.hpp"

namespace widgets {
	struct box final : container {
		enum kind {
			HORIZONTAL, VERTICAL
		};
		explicit box(kind kind);
		[[nodiscard]] int width() const final;
		[[nodiscard]] int height() const final;
		int size() const;
		widget* get(int index) const;
		widget* add(std::unique_ptr<widget> child);
		std::unique_ptr<widget> remove(int index);
		void update_layout() override;
		widget* child_at(int x, int y) override;
	private:
		kind _kind;
		std::vector<std::unique_ptr<widget>> elements;
	};

	[[nodiscard]] std::unique_ptr<box> make_box(box::kind kind);
}  // namespace widgets

#endif  // BOX_HPP_