#include <iostream> // 2021136089 이관우
#include <vector>
#include <sstream>
#include <utility>

const std::vector<std::string> colorKoName{
 "무색", "하양", "빨강", "파랑", "초록"
};
enum class Color {NONE, WHITE, RED, BLUE, GREEN};

std::ostream& operator<<(std::ostream& os, Color color) {
	os << colorKoName[static_cast<int>(color)];
	return os;
}

class Shape {
public:
	virtual ~Shape() = default;
	virtual Shape* clone() const = 0;
	virtual void changeSize(double ratio) noexcept = 0;
	virtual operator std::string() const = 0; // std::string 타입 변환을 가상함수로 정의하면 다른 파생 클래스에서 std::string 으로 변환하는 방식이 다를 경우 이를 재정의할 수 있다.
	static int testPositive(int val) {
		if(val < 0) throw std::runtime_error("");
		return val;
	}
	friend std::ostream& operator<<(std::ostream& os, const Shape& shape);
};

std::ostream& operator<<(std::ostream& os, const Shape& shape){
	os << static_cast<std::string>(shape);
	return os;
}

class Rectangle: public Shape {
private:
	int x;
	int y;
	int width;
	int height;
public:
	Rectangle(int x, int y, int width, int height):
		x{x}, y{y},
		width{Shape::testPositive(width)},
		height{Shape::testPositive(height)} {}
	Rectangle* clone() const final {
		return new Rectangle{*this};
	}
	void changeSize(double ratio) noexcept override {
		width = static_cast<int>(width * ratio);
		height = static_cast<int>(height * ratio);
	}
	operator std::string() const override {
		std::stringstream ss;
		ss << "정사각형(" << x << ", " << y << ",  "
				<< width << ", " << height << ")";
		return ss.str();
	}
};

class Circle: public Shape {
private:
	int x;
	int y;
	int radius;
public:
	Circle(int x, int y, int radius):
		x{x}, y{y}, radius{Shape::testPositive(radius )} {}
	Circle* clone() const final {
		return new Circle{*this};
	}
	void changeSize(double ratio) noexcept final {
		radius = static_cast<int>(radius * ratio);
	}
	operator std::string() const override {
		std::stringstream ss;
		ss << "원(" << x << ", " << y
			<< ", " << radius << ")";
		return ss.str();
	}
};

class GraphicsShapeItem {
public:
	Shape* shape;
	Color color{Color::NONE};
	
	GraphicsShapeItem(Shape* shape): shape{shape} {}

	GraphicsShapeItem(const GraphicsShapeItem& other) : shape{other.shape->clone()}, color{other.color} {} // 복사 생성자

	GraphicsShapeItem(GraphicsShapeItem&& other) noexcept : shape{other.shape}, color{other.color} {
		other.shape = nullptr;
		other.color = Color::NONE;
	} // 이동 생성자

	GraphicsShapeItem& operator=(const GraphicsShapeItem& other) noexcept {
		if(this == &other) {
			GraphicsShapeItem tmp{other};
			swap(tmp);
		}
		return *this;
	} // 복사 대입 연산자

	GraphicsShapeItem& operator=(GraphicsShapeItem&& other) noexcept {
		swap(other);
		return *this;
	} // 이동 대입 연산자

	~GraphicsShapeItem() noexcept {
		delete shape;
	}

	void swap(GraphicsShapeItem& other) noexcept {
		std::swap(shape, other.shape);
		std::swap(color, other.color);
	}

	void changeSize(double ratio) noexcept {
		shape->changeSize(ratio);
	}

	void draw() const {
		std::cout << *shape << '\n';
		std::cout << "도형 그리기: 색:" << color << '\n';
	}
};

int main() {
	GraphicsShapeItem a{new Rectangle{20, 20, 100, 200}};
	GraphicsShapeItem b{a};
	b.changeSize(0.5);
	a.draw();
	b.draw();

	GraphicsShapeItem item1{new Rectangle{10, 10, 100, 100}};
	GraphicsShapeItem item2{new Circle{50, 50, 25}};
	GraphicsShapeItem item3{std::move(item2)};
	GraphicsShapeItem item4{new Rectangle{30, 30, 60, 60}};
	item4 = std::move(item1);
	item3.draw();
	item4.draw();
	return 0;
}