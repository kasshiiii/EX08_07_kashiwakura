#include <iostream>
using namespace std;

class Solid {
public:
    virtual double GetSolidSize() = 0;
};

class Package {
private:
    double size;
    int kuronekoPackageSize[8] = { 60,80,100,120,140,160,180,200 };
    int japanpostPackageSize[7] = { 60,80,100,120,140,160,170 };
public:
    Package(double size) {
        this->size = size;
    }
    void GetPackageSize() {
        int kuroneko, japanpost;
        for (int i = 0; i < _countof(kuronekoPackageSize); i++) {
            if (size <= kuronekoPackageSize[i]) {
                kuroneko = kuronekoPackageSize[i];
                break;
            }
            else {
                kuroneko = 0;
            }
        }
        for (int i = 0; i < _countof(japanpostPackageSize); i++) {
            if (size <= japanpostPackageSize[i]) {
                japanpost = japanpostPackageSize[i];
                break;
            }
            else {
                japanpost = 0;
            }
        }
        cout << "荷物サイズ = " << size << endl;
        if (kuroneko == 0 && japanpost == 0) {
            cout << "クロネコヤマト = 送れません" << "\n日本郵便(ゆうパック) = 送れません" << endl;
        }
        else if (kuroneko == 0) {
            cout << "クロネコヤマト = 送れません" << "\n日本郵便(ゆうパック) = " << japanpost << endl;
        }
        else if (japanpost == 0) {
            cout << "クロネコヤマト = " << kuroneko << "\n日本郵便(ゆうパック) = 送れません" << endl;
        }

        else {
            cout << "クロネコヤマト = " << kuroneko << "\n日本郵便(ゆうパック) = " << japanpost << endl;
        }
    }
};

class Box :public Solid {
private:
    double width;
    double height;
    double depth;
public:
    Box(
        double width,   //幅
        double height,  //高さ
        double depth) {//奥行
        this->width = width;
        this->height = height;
        this->depth = depth;
    }
    double GetWidth() {
        return width;
    }
    double GetHeight() {
        return height;
    }
    double GetDepth() {
        return depth;
    }
    double GetSolidSize() {
        return width + height + depth;
    }
};

class Cylinder :Solid {
private:
    double radius;
    double height;
public:
    Cylinder(
        double radius,   //底辺の半径
        double height) { //高さ
        this->radius = radius;
        this->height = height;
    }
    double GetRadius() {
        return radius;
    }
    double GetHeight() {
        return height;
    }
    double GetSolidSize() {
        return radius * 4.0f + height;
    }
};

class Cone :Solid {
private:
    double bottom;
    double height;
public:
    Cone(
        double bottom,   //底辺の半径
        double height) { //高さ
        this->bottom = bottom;
        this->height = height;
    }
    double GetBottom() {
        return bottom;
    }
    double GetHeight() {
        return height;
    }
    double GetSolidSize() {
        return bottom * 4.0f + height;
    }
};

class Sphere :Solid {
private:
    double radius;
public:
    Sphere(
        double bottom) { //半径
        this->radius = bottom;
    }
    double GetRadius() {
        return radius;
    }
    double GetSolidSize() {
        return radius * 2.0f * 3.0f ;
    }
};

int main()
{
    //float width, height, depth;
    //int kuroneko, japanpost;
    Box box{ 60,50,40 };
    Cylinder cylinder{ 50,50 };
    Cone cone{ 35,20 };
    Sphere sphere{ 30 };
    Package package[]{box.GetSolidSize(),cylinder.GetSolidSize(),cone.GetSolidSize(),sphere.GetSolidSize()};
    for (int i = 0; i < _countof(package); i++) {
        package[i].GetPackageSize();
    }
    
}