// Copyright 2018 Lucas H. Xu 

// error  output  is coded as follows:

// w - is_word
// p - is_palindrome
// a - add
// c - convertbase
// m - multibase

#include <iostream>
#include <string>
using std::string;
using std::cerr;
using std::cout;
using std::cin;


bool is_word(string s) {
  if (s.empty()) {
    return false;
  }
  string criteria("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ");
  string lowercases("abcdefghijklmnopqrstuvwxyz");
  bool has_number = (s.find_first_not_of(criteria) != string::npos);
  if (has_number) {
    return false;
  }
  bool all_lowercase = std::all_of(s.begin(), s.end(), islower);
  bool all_uppercase = std::all_of(s.begin(), s.end(), isupper);
  if (all_lowercase) {
    return true;
  }else if (all_uppercase) {
    return true;
  }else if (isupper(s[0]) && (s.substr(1).find_first_not_of(lowercases) == string::npos)) {
    return true;
  }else {
    return false;
  }
}


bool is_palindrome(string num, bool * error) {
  long temp, rev = 0, digit;

  if (is_word(num)) {
    *error = true;
    return false;
  }

  string numbers("0123456789");
  if (num.find_first_not_of(numbers) != string::npos) {
    *error = true;
    return false;
  }

  if (num[0] == '0' and num.size() == 1) {
    *error = false;
    return true;
  }

  if (num[0] == '0' and num.size() > 1 ) {
    *error = true;
    return false;
  }

  if (std::stol(num) < 0) {
    *error = true;
    return false;
  }
  temp = std::stol(num);
  while (temp > 0) {
    digit = temp % 10;
    rev = rev * 10 + digit;
    temp = temp/10;
  }
//  cout << num << "rev" << rev << "\n";
  bool x = rev == std::stol(num);
//  cout << x << "\n";
  if (rev == std::stol(num)) {
    *error = false;
    return true;
  } else {
    *error = false;
    return false;
  }
}


string add(const string& num1, const string& num2) {
  int carry = 0;
  int len1 = num1.length();
  int len2 = num2.length();
  string num = "";
  string rev_num = "";
  string rev_num1 = "";
  string rev_num2 = "";

  for (int i=len1-1; i>=0; i--){
    rev_num1.push_back(num1[i]);
  }
  // cout << "rev1 " << rev_num1 << "\n";
  for (int i=len2-1; i>=0; i--){
    rev_num2.push_back(num2[i]);
  }
  // cout << "rev2 " << rev_num2 << "\n";

  if (len1 >= len2) {

    for (int i=0; i <len2; i++){
      int sum = ((rev_num1[i] - '0') + (rev_num2[i] - '0') + carry);
      // cout << "sum1 " << sum << "\n";
      num.push_back(sum % 10 + '0');
      carry = sum/10;
    }

    for (int i=len2; i<len1; i++){
      int sum = ((rev_num1[i] - '0') + carry);
      // cout << "sum2 " << sum << "\n";
      num.push_back(sum%10 + '0');
      carry = sum/10;
    }

    if (carry) {
      num.push_back(carry + '0');
    }

  } else {
    for (int i=0; i <len1; i++){
      int sum = ((rev_num2[i] - '0') + (rev_num1[i] - '0') + carry);
      // cout << "sum1 " << sum << "\n";
      num.push_back(sum % 10 + '0');
      carry = sum/10;
    }

    for (int i=len1; i<len2; i++){
      int sum = ((rev_num2[i] - '0') + carry);
      // cout << "sum2 " << sum << "\n";
      num.push_back(sum%10 + '0');
      carry = sum/10;
    }

    if (carry) {
      num.push_back(carry + '0');
    }

  }
  for (int i=num.length()-1; i>=0; i--) {
    rev_num.push_back(num[i]);
  }
  // cout << rev_num << "\n";
  return rev_num;  // fix this line
}


string convertbase(const string& numstr, const int frombase, const int tobase) {
  // convert frombase to base 10

  // convert base 10 to tobase

  return "";  // fix this line
}

string multibase(int x) {
  return "";  // fix this line
}

// leave this line and everything below as is
int main() {
  bool error;
  
  cout << std::boolalpha;
  
//  cout << "Quick Examples\n";
//  cout << "Word: " << is_word("Test") << "\n";
//  cout << "Pal: " << is_palindrome("123456777654321", &error) << "\n";
//  cout << "Add: " << add("123", "456") << "\n";
  cout << "Convert: " << convertbase("1111", 2, 4) << "\n";
//  cout << "Multi: " << multibase(10) << "\n";
  
  cout << "Now running basic tests, errors printed to stderr.\n";
  cerr << std::boolalpha;
  
  // is_word basic tests
  if (not is_word("test")) cerr << "we1\n";
  if (not is_word("Test")) cerr << "we2\n";
  if (not is_word("TEST")) cerr << "we3\n";
  if (not is_word("thisisaword")) cerr << "we4\n";
  
  if (is_word("123")) cerr << "we5\n";
  if (is_word("")) cerr << "we6\n";
  if (is_word("abc123abc")) cerr << "we7\n";
  if (is_word("tEst")) cerr << "we8\n";
  if (is_word("tEst")) cerr << "we9\n";
  if (is_word("TESTer")) cerr << "we10\n";
  
  
  // is_palindrome basic tests
  if (not is_palindrome("12321", &error) or error) cerr << "pe1\n";
  if (not is_palindrome("9009", &error) or error) cerr  << "pe2\n";
  if (not is_palindrome("9", &error) or error)  cerr << "pe3\n";
  if (not is_palindrome("123456777654321", &error) or error) cerr << "pe4\n";
  
  if (is_palindrome("abcba", &error) or not error) cerr << "pe5\n";
  if (is_palindrome("12321 a", &error) or not error) cerr << "pe6\n";
  if (is_palindrome("0012100", &error) or not error) cerr << "pe7\n";
  
  if (is_palindrome("123", &error) or error) cerr << "pe8\n";
  if (is_palindrome("123211", &error) or error) cerr << "pe9\n";
  if (not is_palindrome("0", &error) or error)  cerr << "pe10\n";
  
  // add basic tests
  if (add("123", "456") != "579") cerr << "ae1\n";
  if (add("123", "4") != "127") cerr << "ae2\n";
  if (add("1234", "9") != "1243") cerr << "ae3\n";
  if (add("88", "12") != "100") cerr << "ae4\n";
  if (add("1234567890123456789", "10000000000000999")
      != "1244567890123457788") cerr << "ae5\n";

  string longone(120, '2');
  longone[0] = '3';
  string longother(123, '1');
  longother[0] = '4';
  longother[3] = '2';
  string longresult(123, '3');
  longresult[0] = '4';
  longresult[1] = '1';
  longresult[2] = '1';
  longresult[3] = '5';

  if (add(longone, longother) != longresult ) cerr << "ae6\n";

  // convertbase tests

  if (convertbase("1111", 2, 10) != "15" ) cerr << "ce1\n";
  if (convertbase("255", 10, 16) != "??")  cerr << "ce2\n";
  if (convertbase("755", 8, 2) != "111101101") cerr << "ce3\n";

  if (convertbase("987123", 30, 30) != "987123" ) cerr << "ce4\n";
  if (convertbase("azbc", 100, 10) != "49745051") cerr << "ce5\n";

  if (convertbase("azbc", 100, 2) != "10111101110000110010011011")
    cerr << "ce6\n";
//
//  // multibase tests
//
//  if (multibase(121) != "3 7 8 10 120") cerr << "me1\n";
//  if (multibase(45) != "2 8 14 44") cerr << "me2\n";
//  if (multibase(63) != "2 4 8 20 62") cerr << "me3\n";
//  if (multibase(10) != "3 4 9") cerr << "me4\n";
  
  return 0;
}