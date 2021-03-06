#include "settings_tabpage.hpp"

#include "resource.hpp"
#include "utility.hpp"

#include "button.hpp"

namespace firefly
{
	settings_tabpage::settings_tabpage(main_window* parent)
		: custom_tabpage(parent)
	{

	}

	settings_tabpage::~settings_tabpage()
	{

	}

	void settings_tabpage::save_to_profile(std::string const& profile_path)
	{
		this->profile_writer.set_path(profile_path);
	}
	
	void settings_tabpage::load_from_profile(std::string const& profile_path)
	{
		this->profile_reader.set_path(profile_path);
	}
	
	void settings_tabpage::create_controls(rectangle& rect)
	{
		/* section image */
		std::shared_ptr<button> section_image = std::make_shared<button>(*this);
		section_image.get()->create("", rectangle((rect.width / 2) - (image_size / 2), image_offset, image_size, image_size));
		section_image.get()->set_bitmap(png_button_settings);
		this->store_control(section_image);
		
		/* Auto Pot */
		int auto_pot_seperator_continue = this->create_seperator("General Settings", image_offset + image_size + image_offset);

	}
}