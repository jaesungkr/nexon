// ��� ��� �Լ��� ������ �ƴ� �ʼ� �����Դϴ�.
// ����� ���� �������� ���� ��� ��� �Լ�(getter) �� 
// �ݵ�� ��� ��� �Լ��� ������ �մϴ�.
class Rect
{
	int x, y, w, h;
public:
	Rect(int x, int y, int w, int h) : x{ x }, y{ y }, w{ w }, h{ h } {}

	int getArea() const { return w * h; }
};

//void foo(Rect r) // call by value : ���翡 ���� ������尡 �ִ�.
void foo(const Rect& r) // call by value  ���� const& �� ����.
{
	int n = r.getArea(); // ??
}
int main()
{
	Rect r(1,2,3,4); // ��� ��ü �ƴ�..

	int n = r.getArea(); // ok. 

	foo(r);
}