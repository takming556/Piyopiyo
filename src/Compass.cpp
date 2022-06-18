#include "class.h"

Compass::Compass() {
	direction = UP;
}

Compass::Compass(Direction given_direction) {
	direction = given_direction;
}

void Compass::operator ++(int n) {
	switch (direction) {
	case UP:
		direction = RIGHT;
		break;
	case RIGHT:
		direction = DOWN;
		break;
	case DOWN:
		direction = LEFT;
		break;
	case LEFT:
		direction = UP;
		break;
	}
}

void Compass::operator --(int n) {
	switch (direction) {
	case UP:
		direction = LEFT;
		break;
	case RIGHT:
		direction = UP;
		break;
	case DOWN:
		direction = RIGHT;
		break;
	case LEFT:
		direction = DOWN;
		break;
	}
}

Compass Compass::operator ++() {
	switch (direction) {
	case UP:
		direction = RIGHT;
		break;
	case RIGHT:
		direction = DOWN;
		break;
	case DOWN:
		direction = LEFT;
		break;
	case LEFT:
		direction = UP;
		break;
	}
	return *this;
}

Compass Compass::operator --() {
	switch (direction) {
	case UP:
		direction = LEFT;
		break;
	case RIGHT:
		direction = UP;
		break;
	case DOWN:
		direction = RIGHT;
		break;
	case LEFT:
		direction = DOWN;
		break;
	}
	return *this;
}

void Compass::operator +=(int rotate_amount_plus) {
	for (int i = 0; i < rotate_amount_plus; i++) {
		switch (direction) {
		case UP:
			direction = RIGHT;
			break;
		case RIGHT:
			direction = DOWN;
			break;
		case DOWN:
			direction = LEFT;
			break;
		case LEFT:
			direction = UP;
			break;
		}
	}
}

void Compass::operator -=(int rotate_amount_minus) {
	for (int i = 0; i < rotate_amount_minus; i++) {
		switch (direction) {
		case UP:
			direction = LEFT;
			break;
		case RIGHT:
			direction = UP;
			break;
		case DOWN:
			direction = RIGHT;
			break;
		case LEFT:
			direction = DOWN;
			break;
		}
	}
}

Compass Compass::operator +(int rotate_amount_plus) {
	for (int i = 0; i < rotate_amount_plus; i++) {
		switch (direction) {
		case UP:
			direction = RIGHT;
			break;
		case RIGHT:
			direction = DOWN;
			break;
		case DOWN:
			direction = LEFT;
			break;
		case LEFT:
			direction = UP;
			break;
		}
	}
	return *this;
}

Compass Compass::operator -(int rotate_amount_minus) {
	for (int i = 0; i < rotate_amount_minus; i++) {
		switch (direction) {
		case UP:
			direction = LEFT;
			break;
		case RIGHT:
			direction = UP;
			break;
		case DOWN:
			direction = RIGHT;
			break;
		case LEFT:
			direction = DOWN;
			break;
		}
	}
	return *this;
}

Compass Compass::operator =(Compass righthand) {
	direction = righthand.direction;
	return *this;
}

Compass Compass::operator =(Direction righthand) {
	direction = righthand;
	return *this;
}

bool Compass::operator ==(Compass righthand) {
	return direction == righthand.direction;
}

bool Compass::operator !=(Compass righthand) {
	return direction != righthand.direction;
}

bool Compass::operator ==(Direction righthand) {
	return direction == righthand;
}

bool Compass::operator !=(Direction righthand) {
	return direction != righthand;
}