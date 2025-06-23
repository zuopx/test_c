int func(int a) {};
bool func(bool a) {};
bool func(int a) {};  // cannot overload functions distinguished by return type alone

int main()
{
    func(1);
    return 0;
}