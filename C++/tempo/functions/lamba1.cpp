int addFunc(int a, int b){ return a + b; }

int main(){
    
    struct AddObj{
        int operator()(int a, int b) const { return a + b; }
    };
    
    AddObj addObj;
    addObj(3, 4) == addFunc(3, 4);

}