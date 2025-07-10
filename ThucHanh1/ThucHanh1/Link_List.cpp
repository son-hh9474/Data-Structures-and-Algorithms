#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
using namespace std;

struct node {
	string ok;
	node* link;
};

// tao them phan tu vao cuoi
void add_end(node*& first) {
	// tao phan tu lien ket
	node* p = new node;
	//tao gia tri cho phan tu lien ket
	cin.ignore();
	cout << "nhap chuoi: ";
	getline(cin, p->ok);

	node* q = first; // tao con tro de duyet phan tu
					 // duyet den phan tu tro den null
	if (first != NULL) {
		while (q->link != NULL) {
			q = q->link;
		}
		q->link = p;
		p->link = NULL;
	}
	else {
		first = p;
		p->link = NULL;
	}

	p = NULL;
}
//them phan tu dau 
void add_head(node* first) {
	node* p = new node;
	cin.ignore();
	cout << "nhap chuoi: ";
	getline(cin, p->ok);

	p->link = first;
	first = p;
	p = NULL;
}
//xoa phan tu dau
void delete_head(node*& first) {

	if (first == NULL)
		return;
	node* tmp1 = first;
	if (first->link == NULL) {
		first = NULL;
	}
	else {
		first = tmp1->link;
	}
	delete tmp1;
}

//xoa phan tu cuoi
void delete_end(node*& first) {

	if (first == NULL)
		return;
	node* tmp = NULL;
	node* tmp1 = first;
	if (first->link == NULL) {
		first = NULL;
	}
	else {
		while ((tmp1->link)->link != NULL) {
			tmp1 = tmp1->link;
		}
		node* tmp = tmp1->link;
		tmp1->link = NULL;
	}
	delete tmp;
}
//them phan tu theo index
void deleteAt(node*& first) {
	if (first == NULL)
		return;
	node* tmp = first;
	int dem = 1;
	while (tmp->link != NULL) {
		dem++;
		tmp = tmp->link;
	}
	tmp = first;
	int choose = -1;
	do {
		cout << "nhap index phan tu ma ban muon xoa [1-" << dem << "]: ";
		cin >> choose;
		if (choose < 1 || choose > dem) {
			cout << "nhap sai roi!!!" << endl;
			Sleep(5000);
		}
	} while (choose < 1 || choose > dem);

	if (choose == 1) {
		delete_head(first);
		return;
	}
	else if (choose == dem) {
		delete_end(first);
		return;
	}

	for (int check = 2; check != choose; check++) {
		tmp = tmp->link;
	}

	node* tmp1 = tmp->link;
	tmp->link = tmp1->link;
	delete tmp1;
}

//xoa phan tu theo index
void insertAt(node*& first) {
	if (first == NULL)
		return;
	node* tmp = first;
	int dem = 1;
	while (tmp->link != NULL) {
		dem++;
		tmp = tmp->link;
	}
	tmp = first;
	int choose = -1;
	do {
		cout << "nhap index phan tu ma ban muon xoa [1-" << dem << "]: ";
		cin >> choose;
		if (choose < 1 || choose > dem) {
			cout << "nhap sai roi!!!" << endl;
			Sleep(5000);
		}
	} while (choose < 1 || choose > dem);

	if (choose == dem) {
		add_end(first);
		return;
	}
	else if (choose == 1) {
		add_head(first);
		return;
	}

	for (int check = 2; check != choose; check++) {
		tmp = tmp->link;
	}

	node* p = new node;
	cin.ignore();
	cout << "nhap chuoi: ";
	getline(cin, p->ok);

	p->link = tmp->link;
	tmp->link = p;
	p = NULL;
}
// hien thi lua chon 
int giaoDien() {
	const int max = 7;
	int luaChon = -1;
	do {

		cout << "an mot nut bat ki de tiep tuc: ";
		char ok = _getch();
		system("cls");
		cout << "=================================" << endl;
		cout << "1. tao them phan tu vao cuoi     " << endl;
		cout << "2. ve danh sach lien ket         " << endl;
		cout << "3. xoa phan tu dau               " << endl;
		cout << "4. xoa phan tu cuoi              " << endl;
		cout << "5. them phan tu theo index       " << endl;
		cout << "6. xoa phan tu theo index        " << endl;
		cout << "7. exit                        " << endl;
		cout << "=================================\n\n\n" << endl;
		cout << "nhap lua chon cua ban vao: ";
		cin >> luaChon;

		if (luaChon < 1 || luaChon > max) {
			cout << "ban nhap sai roi!!!" << endl;
			Sleep(5000);
		}
	} while (luaChon < 1 || luaChon > max);


	return luaChon;
}

// hien thi danh sach lien ket
void DrawLinkList(node* first) {

	if (first == NULL)
		return;
	system("cls");
	node* tmp = first;
	while (tmp->link != NULL) {

		cout << "=====================" << endl;
		cout << "=                   =" << endl;
		cout << tmp->ok << endl;
		cout << "=                   =" << endl;
		cout << "=====================" << endl;
		cout << "=                   =" << endl;
		cout << "=         |         =" << endl;
		cout << "==========|==========" << endl;
		cout << "          |          " << endl;
		cout << "          v          " << endl;
		tmp = tmp->link;
	}
	cout << "=====================" << endl;
	cout << "=                   =" << endl;
	cout << tmp->ok << endl;
	cout << "=                   =" << endl;
	cout << "=====================" << endl;
	cout << "=                   =" << endl;
	cout << "=         |         =" << endl;
	cout << "==========|==========" << endl;
	cout << "          |          " << endl;
	cout << "          v          " << endl;
}


// ham xu li
void process() {

	// con tro tro den den phan tu dau danh sach
	node* first = NULL;


	while (true) {

		int res = giaoDien();
		switch (res) {
		case 1:
			add_end(first);
			break;
		case 2:
			DrawLinkList(first);
			break;
		case 3:
			delete_head(first);
			break;
		case 4:
			delete_end(first);
			break;
		case 5:
			deleteAt(first);
			break;
		case 6:
			insertAt(first);
			break;
		case 7:
			return;
		}

	}

}
int main() {

	process();

	return 0;
}