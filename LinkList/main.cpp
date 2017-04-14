#include<iostream>
#include "LinkList.cpp"
#include<string>
using namespace std;
int main()
{
	string str[5] = {"hello","everyone","welcome","to","beijing"};
	//初始化一个链表
	LinkList<string> list1;
	for(int ix=0;ix<5;++ix)
//		list1.insert_head(str[ix]);         //调用insert()，依次插入在链表的头部
        list1.insert_end(str[ix]);
	//遍历链表
	cout<<"遍历链表: ";
	string listEl;
	if(list1.first(listEl))
		cout<<listEl<<" ";    //获得head
	while(list1.getNext(listEl))
		cout<<listEl<<" ";
	cout<<endl;

	LinkList<string> list2(list1);  //调用构造函数初始化
	LinkList<string> list3 = list1;  //调用重载“=”操作符
    list2.first(listEl);
	cout<<"ListEl = "<<listEl<<endl;
	list3.first(listEl);
	cout<<"ListEl = "<<listEl<<endl;
	if(list2.find(str[3]))              //调用find()
		cout<<"str[3] = "<<str[3]<<endl;
	if(list3.retrieve(str[2]))          //调用retrieve()
		cout<<"str[2] = "<<str[2]<<endl;
	if(list3.remove(str[1]))
	{
		list1.first(listEl);
 		cout<<"ListEl after remove is "<<listEl<<endl;
	}
	if(list1.isEmpty())
		cout<<"List is Empty!"<<endl;
	list1.Empty();
	list2.Empty();
	list3.Empty();
	cout<<"hello"<<endl;
	return 0;
}