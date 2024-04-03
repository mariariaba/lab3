#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    double x;
    double y;
    string color;

public:
    Point(double x_val, double y_val, string color_val) : x(x_val), y(y_val), color(color_val) {}

    void display() const {
        setlocale(LC_CTYPE, "ukr");
        cout << "Точка (" << x << ", " << y << ") Колiр: " << color << endl;
    }

    void move(double dx, double dy) {
        x += dx;
        y += dy;
    }

    pair<double, double> get_coordinates() const {
        return make_pair(x, y);
    }
};

class Line {
private:
    Point start;
    Point end;

public:
    Line(const Point& start_point, const Point& end_point) : start(start_point), end(end_point) {}

    void display() const {
        setlocale(LC_CTYPE, "ukr");
        cout << "Лiнiя з ";
        start.display();
        cout << "     до ";
        end.display();
    }

    void move(double dx, double dy) {
        start.move(dx, dy);
        end.move(dx, dy);
    }

    pair<double, double> get_midpoint() const {
        double mid_x = (start.get_coordinates().first + end.get_coordinates().first) / 2;
        double mid_y = (start.get_coordinates().second + end.get_coordinates().second) / 2;
        return make_pair(mid_x, mid_y);
    }

    double get_length() const {
        double dx = start.get_coordinates().first - end.get_coordinates().first;
        double dy = start.get_coordinates().second - end.get_coordinates().second;
        return sqrt(dx * dx + dy * dy);
    }
};

   int main(){
       setlocale(LC_CTYPE, "ukr");


    Point point1(0, 0, "Жовтий");
    Point point2(3, 4, "Зелений");
    point1.display();
    point2.display();

    Line line(point1, point2);
    line.display();
    line.move(1, 1);
    line.display();

    pair<double, double> midpoint = line.get_midpoint();
    double length = line.get_length();

    cout << "Середина лiнiї: (" << midpoint.first << ", " << midpoint.second << ")" << endl;
    cout << "Довжина лiнiї: " << length << endl;

    return 0;
}
