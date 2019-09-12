#include "string.hpp"

String::String() {
    str[0] = 0;
}

String::String(char ch){
    str[0] = ch;
    str[1] = 0;
}

String::String(const char chArray[]){

    int i = 0;
    while(chArray[i] != 0){
        str[i] = chArray[i];
        ++i;
        if(i >= STRING_SIZE)
            break;
    }
    str[i] = 0;
}

int String::length() const {
    int result = 0;
    while(str[result] != 0)
        ++result;
    return result;
}

String String::operator+(const String& rhs)  const{
    String temp(str);
    int offset = length();
    int i = 0;
    while(rhs.str[i] != 0){
        if(offset + i == STRING_SIZE)
            break;
        temp.str[offset + i] = rhs.str[i];
        ++i;
    }
    temp.str[offset + i] = 0;
    return temp;
    
    
}

String operator+(char lhs, const String &rhs){ return String(lhs) + rhs;};

String operator+(const char lhs[], const String& rhs){ return String(lhs) + rhs;};

String& String::operator+=(const String& rhs){
    int offset = length();
    int i = 0;
    
    while(rhs.str[i] != 0){
        if(offset + i == STRING_SIZE)
            break;
        str[offset + i] = rhs.str[i];
        ++i;
    }
    str[offset + i] = 0;
    return *(this);
}

char String::operator[](int i) const {
    return str[i];
}

char& String::operator[](int i) {
    return str[i];
}

bool String::operator<(const String& rhs) const{
    int i = 0;
    while(str[i] != 0 && rhs.str[i] != 0 && str[i] == rhs.str[i])
        ++i;
    return str[i] < rhs.str[i];
}

bool operator==(char lhs, const String& rhs){ return String(lhs) == rhs;};
bool operator==(const char lhs[], const String& rhs){return String(lhs) == rhs;};


bool String::operator==(const String& rhs) const {
    int i = 0;
    while((str[i] != 0) && (str[i] == rhs.str[i]))
        ++i;
    return str[i] == rhs.str[i];
}


std::ostream& operator<<(std::ostream& out, const String& rhs){
    int i = 0;
    while(rhs.str[i] != 0){
        out << rhs.str[i];
        ++i;
    }
    return out;
}

std::istream& operator>>(std::istream& in, String& rhs){
    char buff[STRING_SIZE];
    if(!in.eof()){
        in >> buff;
        rhs = String(buff);
    }
    else{
        rhs = String();
    }
    return in;
}

String String::substr(int start, int end) const{
    if(start < 0)
        start = 0;
    if(end < 0)
        return "";
    if(start >= length())
        return "";
    if(end >= length())
        end = length() - 1;
    if(start > end)
        return "";
    
    String result;
    for(int i = start; i < end; ++i){
        result += str[i];
    }
    return result;
    
}


int String::findchar(const char ch, const int start) const{
    String temp = substr(start, length());
    int firstOccurence = -1;
            
    for (int i = 0; i < length(); ++i) {
        if (temp[i] == ch) {
            return firstOccurence = i + start;
        }
    }
            
    return firstOccurence;
}

bool operator>(const String& lhs, const String& rhs) {

    if(!(lhs < rhs) && !(lhs == rhs))
        return true;
    else
        return false;
}

bool operator<=(const String& lhs, const String& rhs) {
    if(((lhs < rhs) || (lhs == rhs)) && !(lhs > rhs))
        return true;
    else
        return false;
}

bool operator>=(const String& lhs, const String& rhs) {
    if(((lhs > rhs) || (lhs == rhs)) && !(lhs < rhs))
        return true;
    else
        return false;
}


bool operator!=(const String& lhs, const String& rhs) {
    if((lhs > rhs) || (lhs < rhs))
        return true;
    else
        return false;
}


bool operator<(const char lhs[], const String& rhs){
    if(String(lhs) < rhs)
         return true;
    else
        return false;
}

bool operator<(char ch, const String& rhs){
    if(String(ch) < rhs)
        return true;
    else
        return false;
}



int String::capacity() const{
    return STRING_SIZE - 1;
}

int String::findstr(int pos, const String& rhs) const {
    String temp = substr(pos, length());
    char lookingFor = rhs[0];
    int foundAt = 0;
    for(int i = 0; i < temp.length(); ++i){
        if(temp[i] != lookingFor){
            foundAt = -1;
            ++i;
        }
    
        if(temp[i] == lookingFor){ 
            foundAt = i;
            break;
        }
    }
    for(int j = foundAt; j < rhs.length(); ++j)
        if(temp[j] != rhs[j - foundAt])
            foundAt = -1;

    return foundAt;

}



