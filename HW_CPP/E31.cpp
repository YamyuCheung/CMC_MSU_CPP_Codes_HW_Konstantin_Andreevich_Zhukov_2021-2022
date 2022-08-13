#include <iostream>
#include <vector>
#include <list>
#include<algorithm>

using namespace std;

void Show(const int ptr)
{
 cout << ptr << " ";
}

bool Compare(int r1,int r2)
{
 if(abs(r1)<abs(r2))
  return true;
 else
  return false;
}

int main()
{
 const int NUM = 5;
 std::vector<int> vi(NUM);  //создает вектор из NUM чисел

 for (int i = 0; i < NUM; i++)
  vi[i] = 3 - 2 * i;
 for (int i = 0; i < NUM; i++)
  cout << vi[i] << " ";
 cout << endl;

 vector<int>::iterator pd = vi.begin(); // vi.begin() нулевой элемент
 *pd = 7;  //vi[0]=7;
 pd++;
 *pd = 4; //vi[1]=4;

 for (pd = vi.begin(); pd != vi.end(); pd++)
  cout << *pd << " ";
 cout << endl;

 list<int> li = { 11,12,13,14,15 }; // двунаправленный список
 list<int>::iterator pl;
 for (pl = li.begin(); pl != li.end(); pl++)
  cout << *pl << " ";
 cout << endl;

 cout << "list " << li.size() << " vector " << vi.size() << endl;
 li.push_back(9);
 vi.push_back(7);
 li.push_front(5);
 //vi.push_front(8); --error
 vi.erase(vi.begin(), vi.begin() + 2);
 //li.erase(li.begin(), li.begin() + 2);
 pl = li.begin(); pl++; pl++;
 li.erase(li.begin(), pl);

 for (pl = li.begin(); pl != li.end(); pl++)
  cout << *pl << " ";
 cout << endl;

 for (pd = vi.begin(); pd != vi.end(); pd++)
  cout << *pd << " ";
 cout << endl;

 for_each(vi.begin(), vi.end(), Show); cout << endl;
 for_each(li.begin(), li.end(), Show); cout << endl;
 for_each(vi.rbegin(), vi.rend(), Show); cout << endl;

 sort(vi.begin(), vi.end());
 for_each(vi.begin(), vi.end(), Show); cout << endl;
 sort(vi.begin(), vi.end(),Compare);
 for_each(vi.begin(), vi.end(), Show);

 return 0;
}
