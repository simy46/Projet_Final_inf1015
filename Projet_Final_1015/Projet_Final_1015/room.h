#pragma once



class Room {

private:
	int line_;
	int column_;
	int size_;
	int floor_;

public:

	Room();
	Room(int l, int c, int e, int s);

	int getLine() const;
	int getColumn() const;
	int getSize() const;
	int getFloor() const;

	void setLine(int l);
	void setColumn(int c);
	void setSize(int s);
	void setFloor(int f);

};