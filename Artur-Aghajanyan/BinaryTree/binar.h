#include <iostream>

class Binary{
	private:
		int value;
		Binary *left, *right;
	public:
		Binary();
		Binary(int value);
		void print(Binary*);
		Binary* insert(Binary* ,int val);
};


Binary::Binary() {
	this->value = 0;
	this->left = this->right = nullptr;
}

Binary::Binary(int value) {
	this->value = value;
	this->left = this->right = nullptr;
}

Binary* Binary::insert(Binary* bin, int value) {
	if(!bin)
		return new Binary(value);
	
	if(bin->value > value)
		bin->left = insert(bin->left, value);
	
	if(bin->value < value)
		bin->right = insert(bin->right, value);

	return bin;
}

void Binary::print(Binary* root) {
	if(root != nullptr){
		if(!root) return;
		std::cout << root->value << " - Value\n";
		print(root->right);
	}
}
