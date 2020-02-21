#include <iostream>
    using namespace std;
    class poly
    {
        protected:
        int width, height;
        public:
        void set_values(int a, int b)
        {
            width = a; height = b;
        }
    };
    class Coutput
    {
        public:
        void output(int i);
    };
    void Coutput::output(int i)
    {
        cout << i;
    }
    class rect:public poly, public Coutput
    {
        public:
        int area()
        {
            return(width * height);
        }
    };
    class tri:public poly, public Coutput
    {
        public:
        int area()
        {
            return(width * height / 2);
        }
    };
    int main()
    {
        rect rect;
        tri trgl;
        rect.set_values(3, 4);
        trgl.set_values(4, 5);
        rect.output(rect.area());
        trgl.output(trgl.area());
        return 0;
    }