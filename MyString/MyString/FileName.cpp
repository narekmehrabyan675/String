#include <iostream>
using namespace std;
class myString {
private:
    char* arr;
    int size;
public:
    myString() {
        size = 1;
        arr = new char[size];
        arr[0] = '\0';
    }
    myString(char* arr, int size) {
        this->size = size;
        this->arr = new char[size + 1];
        for (int i = 0; i < size; i++) {
            this->arr[i] = arr[i];
        }
        this->arr[size] = '\0';
    }
    myString(const myString& obj) {//copy construptor
        this->size = obj.size;
        this->arr = new char[obj.size + 1];
        for (int i = 0; i < this->size; i++) {
            this->arr[i] = obj.arr[i];
        }
        arr[obj.size] = '\0';
        cout << "Call of copy constructor " << this << endl;
    }
    myString operator+(myString& other) {//OPERATOR +
        myString obj;
        obj.size = this->size + other.size + 1;
        obj.arr = new char[this->size + other.size + 1];
        int i = 0;
        for (; i < this->size; i++) {
            obj.arr[i] = this->arr[i];
        }
        for (int j = 0; j < other.size; j++, i++) {
            obj.arr[i] = other.arr[j];
        }
        obj.arr[this->size + other.size] = '\0';
        cout << "Call of operator + " << endl;
        return obj;
    }
    myString operator=(const myString& obj) {//OPERATOR =
        if (this->arr != nullptr)
        {
            delete[] arr;
        }
        this->size = obj.size;
        this->arr = new char[obj.size + 1];
        for (int i = 0; i < this->size; i++) {
            this->arr[i] = obj.arr[i];
        }
        arr[obj.size] = '\0';
        cout << "Call of = operator " << endl;
        return *this;
    }
    char& operator[](int index)//OPERATOR []
    {
        char emptyvalue = { 0 };
        cout << "Call of [] operator " << endl;
        if (index<0 || index>(this->size)) {
            cout << "You write wrong number";
            return emptyvalue;
        }
        return this->arr[index];
    }
    myString& operator+=(const myString& other) {//OPERATOR +=
        myString help;
        help.size = this->size + other.size;
        help.arr = new char[help.size + 1];
        int i = 0;
        for (; i < this->size; i++) {
            help.arr[i] = this->arr[i];
        }
        for (int j = 0; j < other.size; j++, i++) {
            help.arr[i] = other.arr[j];
        }
        help.arr[help.size] = '\0';
        delete[] this->arr;
        this->arr = new char[help.size];
        this->size = help.size;
        for (int i = 0; i < this->size; i++) {
             this->arr[i] = help.arr[i];
        }
        cout << "Call of += operator " << endl;
        return *this;
    }
    bool operator==(const myString& other) {//OPERATOR ==
        cout << "Call of == operator " << endl;
        if (this->size != other.size) {
            return false;
        }
        for (int i = 0; i < this->size; i++) {
            if (this->arr[i] != other.arr[i]) {
                return false;
            }
        }
        return true;
    }
    bool operator!=(const myString& other) {//OPERATOR !=
        cout << "Call of != operator " << endl;
        return !(this->operator==(other));
    }
    bool operator<(const myString& other) {//OPERATOR <
        cout << "Call of < operator " << endl;
        if (this->size < other.size) {
            return true;
        }
        else {
            return false;
        }
    }
    friend istream& operator>>(istream& in,myString& obj) {
        int leinght;
        cout << "Write leinght of word" << endl;
        cin >> leinght;
        obj.size = leinght;
        obj.arr = new char[leinght+1];
        for (int i = 0; i < obj.size;i++) {
            in >> obj.arr[i];
        }
        obj.arr[leinght] = '\0';
        return in;
    }
    friend ostream& operator<<(ostream& out,myString& obj) {
        for (int i = 0; i < obj.size; i++) {
            out << obj.arr[i];
        }
        return out;
    }
    static int find(myString S,myString W) {
        int i{};
        int j{};
        int number = 0;
        for (i = 0; i < S.size - W.size + 1; i++) {
            j = 0;
            while (j < W.size && (S.arr[i + j] == W.arr[j])) {
                j = j + 1;
            }
            if (j == W.size) {
                number++;
                cout << "Word entry " << (W.arr) << " number of position :" << i << endl << "How many times is it repeated:" << number << endl;
            }
        }
        return number;
    }
    static myString output_from_index_and_size_String(myString obj, int size , int index) {//
        myString help;
        help.size = size + 1;
        help.arr = new char[size + 1];
        for (int i = 0; i < size;i++,index++) {
            help.arr[i] = obj.arr[index];
        }
        help.arr[size] = '\0';
        return help;
    }
    void print() {
        for (int i = 0; i < this->size; i++) {
            cout << arr[i];
        }
        cout << endl;
    }
    ~myString() {
        delete[] arr;
        //cout << "call of destruct " << this << endl;
    }
};
int main()
{
    char name_1[] = "Narek";
    char sname_1[] = "Mehrabyan";
    myString name(name_1, 5);
    myString sname(sname_1, 10);
    myString test1;
    //cin >> test;
    cin >> test1;
    cout << test1;
    
    return 0;
}  