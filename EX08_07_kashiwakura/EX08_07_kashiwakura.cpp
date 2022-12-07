#include <iostream>
using namespace std;

class Solid {
public:
    virtual int GetPackageSize() = 0;
};


class Package : public Solid {
private:
    float width, height, depth;
    int BoxSize[8] = { 60,80,100,120,140,160,180,200 };
public:
    Package(float width, float height, float depth) {
        this->width = width;
        this->height = height;
        this->depth = depth;
    }
    int GetPackageSize() {
        float size = width + height + depth;
        for (int i = 0; i < sizeof BoxSize / sizeof BoxSize[0]; i++) {
            if (size < BoxSize[i]) {
                return BoxSize[i];
            }
        }
    }
};
int main()
{
    float width, height, depth;
    cout << "幅を入力してください" << endl;
    cin >> width;
    cout << "高さを入力してください" << endl;
    cin >> height;
    cout << "奥行きを入力してください" << endl;
    cin >> depth;
    Package* package = new Package(width, height, depth);
    cout << "表面積 = " << package->GetPackageSize() << endl;
}