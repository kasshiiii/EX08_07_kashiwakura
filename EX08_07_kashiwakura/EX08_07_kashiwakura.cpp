#include <iostream>
using namespace std;

class Solid {
public:
    virtual void GetPackageSize(int&,int&) = 0;
};


class Package : public Solid {
private:
    float width, height, depth;
    int kuronekoBoxSize[8] = { 60,80,100,120,140,160,180,200 };
    int japanpostBoxSize[7] = { 60,80,100,120,140,160,170 };
public:
    Package(float width, float height, float depth) {
        this->width = width;
        this->height = height;
        this->depth = depth;
    }
    void GetPackageSize(int &kuroneko,int &japanpost) {
        float size = width + height + depth;
        for (int i = 0; i < _countof(kuronekoBoxSize); i++) {
            if (size <= kuronekoBoxSize[i]) {
                kuroneko = kuronekoBoxSize[i];
                break;
            }
            else {
                kuroneko = 0;
            }
        }
        for (int i = 0; i < _countof(japanpostBoxSize); i++) {
            if (size <= japanpostBoxSize[i]) {
                japanpost = japanpostBoxSize[i];
                break;
            }
            else {
                japanpost = 0;
            }
        }
    }
};
int main()
{
    float width, height, depth;
    int kuroneko, japanpost;
    cout << "幅を入力してください" << endl;
    cin >> width;
    cout << "高さを入力してください" << endl;
    cin >> height;
    cout << "奥行きを入力してください" << endl;
    cin >> depth;
    Package* package = new Package(width, height, depth);
    package->GetPackageSize(kuroneko, japanpost);
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