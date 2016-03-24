#include <iostream>
#include <fstream>

using namespace std;

bool login {

};

int main() {
    char buff[50];
    ifstream us("users.txt");
    string users( (istreambuf_iterator<char>(us) ), (istreambuf_iterator<char>() ));
    cout<<users;
}