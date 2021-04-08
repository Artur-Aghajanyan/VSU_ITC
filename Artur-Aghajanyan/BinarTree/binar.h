#include <iostream>

class Binar{
	private:
		int value;
		Binar *left, *right;
	public:
		Binar();
		Binar(int value);
		void print(Binar*);
		Binar* insert(Binar* ,int val);
};


Binar::Binar() {
	this->value = 0;
	this->left = this->right = nullptr;
}

Binar::Binar(int value) {
	this->value = value;
	this->left = this->right = nullptr;
}

Binar* Binar::insert(Binar* bin, int value) {
	if(!bin)
		return new Binar(value);
	
	if(bin->value > value)
		bin->left = insert(bin->left, value);
	
	if(bin->value < value)
		bin->right = insert(bin->right, value);

	return bin;
}

void Binar::print(Binar* root) {
	if(root != nullptr){
		if(!root) return;
		std::cout << root->value << " - Value\n";
		print(root->right);
	}
}
