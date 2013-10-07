#pragma once
class Top {
public:
	Top();
	virtual ~Top();
	virtual void speackClearly();
	virtual Top* clone() const;
	
protected:
	float data_Top;
};

class Middle1
{
public:
	Middle1();
	virtual ~Middle1();
	virtual void Middl1Own();
	virtual Middle1* clone() const;
	virtual Middle1* pure() = 0;
protected:
	float data_Middle1;
};

class Middle2 
{
public:
	Middle2();
	virtual ~Middle2();
	virtual void Middl2Own();
	virtual Middle2* clone() const;
protected:
	float data_Middle2;
};

class Diamond1 : public Middle1, public Middle2 {
public:
	Diamond1();
	virtual ~Diamond1();
	virtual Diamond1* clone() const;
	virtual Diamond1* pure();
protected:
	float data_Diamond1;
};


