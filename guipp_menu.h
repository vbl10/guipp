#pragma once
#include "guipp.h"
#include "guipp_icon.h"
#include <vector>
#include <string>
#include <functional>

namespace guipp
{
	class Menu : public Object
	{
	public:
		static std::unique_ptr<ext::TextFormat> font;
	private:
		class Item
		{
		protected:
			Item(const std::wstring& label, std::shared_ptr<Icon> icon = nullptr) :label(label), icon(icon) {}
		public:
			std::wstring label;
			std::shared_ptr<Icon> icon;
			bool bEnabled = true;
			virtual bool OnClick(const Menu& menu, Window& wnd, bool bElsewhere = false) = 0;
		};
	public:
		typedef std::vector<std::shared_ptr<Item>> vec;
		class Button : public Item
		{
		public:
			Button(const std::wstring& label, std::function<void(int)> func);
			Button(const std::wstring& label, int id, std::function<void(int)> func);
			Button(const std::wstring& label, std::shared_ptr<Icon> icon, int id, std::function<void(int)> func);
			std::function<void(int)> func;
			int id = 0;
		private:
			bool OnClick(const Menu& menu, MainWindow& app, bool bElsewhere) override;
		};
		class Sub : public Item
		{
			class WndSub : public ext::Window, public ext::D2DGraphics
			{
			public:
				WndSub();
			};
		public:
			Sub(const std::wstring& label, vec items);
			Sub(const std::wstring& label, std::shared_ptr<Icon> icon, vec items);
			void Show(bool bShow = true);
		private:
			bool OnClick(const Menu& menu, MainWindow& app, bool bElsewhere) override;
			Item* callback;
		};
		enum ORIENTATION { OR_HORIZONTAL, OR_VERTICAL };
		Menu(ORIENTATION orient, vec items);
		vec items;
	private:
		Item* callback;
	};
}