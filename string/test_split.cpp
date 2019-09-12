// String split method tests
//
// Tests: Split
// Lucas Miller
//
//


#include "string.hpp"
#include <cassert>
int main() {
    {
        String str = "Hello-world-!";
        std::vector<String> result;
        
        result = str.split('-');
        std::cout << "Size of Vector: " << result.size() << std::endl;
        std::cout << result[0] << std::endl;
        std::cout << result[1] << std::endl;
        std::cout << result[2] << std::endl;
        //std::cout << result[3] << std::endl;
        assert(result.size() == 3);
    
    }




    {
        String str = "Hello--world-!";
        std::vector<String> result;
        
        result = str.split('-');
        std::cout << "Size of Vector: " << result.size() << std::endl;;
        assert(result.size() == 4);
    }


    {
        String str = "-a--b-";
        std::vector<String> result;
        
        result = str.split('-');
        std::cout << "Size of Vector: " << result.size() << std::endl;; 
        std::cout << result[0] << std::endl;
        std::cout << result[1] << std::endl;
        std::cout << result[2] << std::endl;
        std::cout << result[3] << std::endl;  
       //std::cout << result[4] << std::endl;
        assert(result.size() == 5);
    }

    {
        String str = "a--b";
        std::vector<String> result;
        
        result = str.split('-');
        std::cout << "Size of Vector: " << result.size() << std::endl;
        std::cout << result[0] << std::endl;
        std::cout << result[1] << std::endl;
        //std::cout << result[2] << std::endl;


        assert(result.size() == 3);
    }



    {
        String str = "a--b";
        std::vector<String> result;
        
        result = str.split('-');
        std::cout << "Size of Vector: " << result.size() << std::endl;; 
        std::cout << result[0] << std::endl;
        std::cout << result[1] << std::endl;
        std::cout << result[2] << std::endl;
        //std::cout << result[3] << std::endl;
        assert(result.size() == 3);
    }

     {
        String str = "This is a test!";
        std::vector<String> result;
        
        result = str.split(' ');
        std::cout << "Size of Vector: " << result.size() << std::endl;; 
        assert(result.size() == 4);
    }   



     {
        String str = "This is a-test!";
        std::vector<String> result;
        
        result = str.split(' ');
        std::cout << "Size of Vector: " << result.size() << std::endl;; 
        assert(result.size() == 3);
    }  




    {
        String str = "-a--b-";
        std::vector<String> result;
        
        result = str.split('-');
        std::cout << "Size of Vector: " << result.size() << std::endl;; 
        assert(result.size() == 5);
    }


    {
        String str = "-a--b-c";
        std::vector<String> result;
        
        result = str.split('-');
        std::cout << "Size of Vector: " << result.size() << std::endl;; 
        assert(result.size() == 5);
    }


    {
        String str = "131.123.32.16 - - [18/Sep/2002:12:06:12 -0400] \"GET /~collard/class/oop/master.css HTTP/1.1\" 200 791";
        std::vector<String> result;
        
        result = str.split(' ');
        std::cout << "Size of Vector: " << result.size() << std::endl;
        std::cout << result[0] << std::endl;
        std::cout << result[1] << std::endl;
        std::cout << result[2] << std::endl;
        std::cout << result[3] << std::endl;
        std::cout << result[4] << std::endl;
        std::cout << result[5] << std::endl;
        std::cout << result[6] << std::endl;
        std::cout << result[7] << std::endl;
        std::cout << result[8] << std::endl;
        std::cout << result[9] << std::endl;          
        assert(result.size() == 10);
    }


}
