
#include "iostream"
using namespace std;
//ROOT KAYBEDÝLMEYECEK
struct node {
	int data;
	node *next;
};
node *ekle(node *r, int x) {
	if (r == NULL) {
		r = new node;
		r->data = x;
		r->next = NULL;
	}
	else {
		node *yrd = r;
		while (yrd->next != NULL) {
			yrd = yrd->next;
		}
		//whileden sonra listenin son elemanýna eriþmiþ olacaðým ekleme iþlemini yapabilceðim
		yrd->next = new node;
		yrd->next->data = x;
		yrd->next->next = NULL;
	}
	return r;
}
void yazdir(node *r) {
	while (r->next != NULL) {
		cout << r->data << " ";
		r = r->next;
	}
	//son eleman nexti null oalacaðýnda ekstra eklesdim son elemaný
	cout << r->data << " ";
	r = r->next;
}
node *basaekle(node *r, int x) {
	node *yrd;
	yrd = new node;
	yrd->next = r;
	yrd->data = x;
	r = yrd;
	return r;

}

void arayaekle(node *r, int x, int hangiara) {
	node *tmp;//eklenecek node oluþturuldu
	tmp = new node;
	tmp->data = x;

	node *yrd = r;
	while (yrd->next->data != hangiara)//eklenecek yeri buldum
	{
		yrd = yrd->next;
	}

	tmp->next = yrd->next;
	yrd->next = tmp;

}
void sil(node *r, int hangiara) {
	node *yrd = r;
	while (yrd->next->data != hangiara)//sýkýntý
	{
		yrd = yrd->next;
	}
	node *tmp;
	tmp = yrd->next;

	yrd->next = tmp->next;
	tmp->next = NULL;
	delete tmp;

}

class dizi {
public:
	node *root=NULL;
	dizi(int x) {
		root = new node;
		root->data = x;
		root->next = NULL;
	}
	void ekle(int x) {
		node *yrd=root;
		while (yrd->next != NULL) {
			yrd = yrd->next;
		}
		//whileden sonra listenin son elemanýna eriþmiþ olacaðým ekleme iþlemini yapabilceðim
		yrd->next = new node;
		yrd->next->data = x;
		yrd->next->next = NULL;
	}
	void sil(int indis) {//verilen indisi listeden siler
		node *yrd=root;
		if (indis == 0) {//rootu silmek istiyor demektir
			root = root->next;
		}
		else {
			for (int i = 1; i < indis; i++)
			{
				yrd = yrd->next;
			}//bu iþlemin sonunda silinecek node ulaþýcaz (silineek deðerden 1 öncesinde durmamýz lazým)
			node *tmp = yrd->next;//silinecek node
			yrd->next = tmp->next;
		}
	}
	void yazdir() {//tüm listeyiekrana yazdýrýr
		node *yrd = root;
		while (yrd->next!=NULL)
		{
			cout << yrd->data << " ";
			yrd = yrd->next;
		}
		cout << yrd->data << " ";//son elemaný yazdýr
	}
	int getir(int indis) {//verilen indis deðerine ait node deðerini getirir
		node *yrd=root;
		for (int i = 0; i < indis; i++)
		{
			yrd = yrd->next;
		}//döndürülmesi gereken deðer bulundu yrd
		return yrd->data;
	}


};


void main()
{ /*
	node *root = NULL;

	root = ekle(root, 10);
	for (int i = 0; i < 15; i++)
	{
		ekle(root, i + 7);
	}
	root = basaekle(root, 0);


	arayaekle(root, 111, 8);
	yazdir(root);
	sil(root, 111);
	cout << endl;
	yazdir(root);
	*/
	dizi d(10);
	for (int i = 0; i < 10; i++)
	{
		d.ekle(i + 11);
	}
	d.yazdir();
	cout << endl;
	d.sil(0);
	d.yazdir();

	cout<<endl << d.getir(3);


	system("pause");

}

