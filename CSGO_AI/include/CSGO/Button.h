#pragma once
#include <Windows.h>
#include <iostream>
#include <string>

class Button
{
public:
	Button(const std::string& button_name = "Button", int button = plus_key_code);
	void update();
	void set_toggle_button(int button);
	bool was_clicked() const;
	bool is_toggled() const;

private:
	bool is_key_down(unsigned short key_state) const;
	std::string button_name;
	int button = 0;
	static constexpr int plus_key_code = 0xBB;

	bool was_previous_update_down = false;
	bool new_click = false;
	bool toggled = false;
};

