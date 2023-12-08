#include "guipp_menu.h"

using namespace guipp;

std::unique_ptr<ext::TextFormat> Menu::font;

Menu::Button::Button(const std::wstring& label, std::function<void(int)> func)
	:Item(label), func(func)
{
}
Menu::Button::Button(const std::wstring& label, int id, std::function<void(int)> func)
	:Item(label), func(func), id(id)
{
}
Menu::Button::Button(const std::wstring& label, std::shared_ptr<Icon> icon, int id, std::function<void(int)> func)
	:Item(label, icon), func(func), id(id)
{
}
bool Menu::Button::OnClick(const Menu& menu, MainWindow& app, bool bElsewhere)
{
	return false;
}

Menu::Sub::Sub(const std::wstring& label, vec items)
	:Item(label)
{

}
Menu::Sub::Sub(const std::wstring& label, std::shared_ptr<Icon> icon, vec items)
	:Item(label)
{

}
void Menu::Sub::Show(bool bShow = true)
{
	
}
bool Menu::Sub::OnClick(const Menu& menu, MainWindow& app, bool bElsewhere)
{
	return true;
}


Menu::Menu(ORIENTATION orient, vec items)
{
}