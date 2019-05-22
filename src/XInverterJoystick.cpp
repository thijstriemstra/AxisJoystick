#include "XInverterJoystick.h"

XInverterJoystick::XInverterJoystick(Joystick* origin)
	: DelegateJoystick(origin) {
}

Joystick::Move XInverterJoystick::singleRead() {
	return invert(DelegateJoystick::singleRead());
}

Joystick::Move XInverterJoystick::multipleRead() {
	return invert(DelegateJoystick::multipleRead());
}

Joystick::Move XInverterJoystick::invert(const Joystick::Move move) {
	switch (move) {
		case Move::LEFT:
			return Move::RIGHT;
		case Move::RIGHT:
			return Move::LEFT;
		default:
			return move;
	}
}

boolean XInverterJoystick::isRight() {
	return DelegateJoystick::isLeft();
}

boolean XInverterJoystick::isLeft() {
	return DelegateJoystick::isRight();
}