#pragma once
#include<stdlib.h>;     
#include<iostream>;
#include <fstream>;
#include <limits>;

#include"ODList.h";

using namespace std;




class File {
public:
    std::fstream file;
public:
    //friend ODList<T>;
  
    

    inline File() 
    {
        char* fname2 = _strdup("C:/Users/Lenovo/source/repos/Project2.1.8/text.txt");
        Open(fname2, ios::in | ios::out );
    }

    inline File(char* name, long int mode) 
    {
        Open(name, mode);
    }

    inline ~File() 
    {
        Close();
    }




    inline void Open(char* name, long int mode)
    {
        file.open(name, ios::openmode(mode));
    }



  /*  void readStd(ODList<T>* add, int size)
    {
        char cur[200];
        int ctr = 0;
        int y = 0;
        char ch;
        ReadContent(&ch, 1);
        
            while (ch != '\n')
            {
                int dgh = GetPointerPosition();
                *(cur + y) = ch;
                y++;
                SetPointerPosition(y);
                ReadContent(&ch, 1);
            }
        
            add->
  
    }*/



    int myseek(int i)
    {
        SetPointerPosition(0);
        char cur[200];
        int ctr = 0;
        int y = 0;
        char ch;
        if (i != 0)
        {
            ReadContent(&ch, 1);
            while (ctr < i)
            {
                while (ch != '*')
                {
                    int dgh = GetPointerPosition();
                    *(cur + y) = ch;
                    y++;
                    SetPointerPosition(y);
                    ReadContent(&ch, 1);
                }
                ctr++;
            }
        }
        return y;
    }
    

    const static long int moveToEnd = 1L << 1;
    const static long int asBinary = 1L << 2;
    const static long int forInput = 1L << 3;
    const static long int forOutput = 1L << 4;
    const static long int truncate = 1L << 5;

    inline bool OpenAndCheck(char* name, long int mode)
    {
        Open(name, mode);
        return IsAllRight();
    }

    inline bool IsOpened() 
    {
        return file.is_open();
    }

    inline void Close()
    {
        file.close();
    }

   
    template <class type>  
    friend ofstream& operator<<(File& out, type& variable);

    template <class type>  
    friend ifstream& operator>>(File& in, type& variable);

    template <class type> 
    inline void ReadContent(type* pointer, int length) 
    {
        file.read(reinterpret_cast<char*>(pointer), length);
    }

    inline void ReadContent(char* pointer, int length)
    {
        file.read(pointer, length);
    }

    inline void ReadString(char* pointer, int length)
    {
        file.read(pointer, length);
        *(pointer + length) = '\0';
    }

    inline void ReadOne(char* pointer)
    {
        char ch;
        int i = 0;

        ReadContent(&ch, 1);
        while (ch != '\0') {
            *(pointer + i) = ch;
            i++;
            ReadContent(&ch, 1);
        }
        *(pointer + i) = '\0';
    }

    template <class type> inline void Read(type* pointer)
    {
        ReadContent(reinterpret_cast<char*>(pointer), sizeof(pointer));
    }

    template <class type> inline void Read(type* array, int length) 
    {
        ReadContent(reinterpret_cast<char*>(array), sizeof(type) * length);
    }

    template <class type> inline void ReadBlock(type* pointer)
    {
        file >> *pointer;
    }



    template <class type> inline void WriteContent(type* pointer, int length) 
    {
        file.write(reinterpret_cast<char*>(pointer), length);
    }

    inline void WriteContent(char* pointer, int length)
    {
        file.write(pointer, length);
    }

    inline void WriteOne(char* pointer) 
    {
        int i = 0;
        while (*(pointer + i) != '\0')
        {
            WriteContent(pointer + i, 1);
            i++;
        }
        WriteContent(pointer + i, 1);
    }

    template <class type> inline void Write(type* pointer)
    {
        WriteContent(reinterpret_cast<char*>(pointer), sizeof(type));
    }

    template <class type> inline void Write(type* array, int length) 
    {
        WriteContent(reinterpret_cast<char*>(array), sizeof(type) * length);
    }

    template <class type> inline void WriteAsText(type variable)
    {
        file << variable;
    }

    template <class type> inline void WriteAsText(type* pointer) 
    {
        file << *pointer;
    }



    inline int GetPointerPosition() 
    {
        return file.tellp();
    }

    inline void SetPointerPosition(int position)
    {
        file.seekp(position);
    }

    inline void SetPointerPosition(int position, long int base)
    {
        file.seekp(position, std::ios_base::seekdir(base));
    }

    const static long int beginning = 0L;
    const static long int currentPosition = 1L << 0;
    const static long int end = 1L << 1;


    inline bool IsAllRight()
    {
        return file.good();
    }
};

template <class type>
ofstream& operator<<(File& out, type& variable)
{
    out.file << variable;
    return out.file;
};

template <class type>
ifstream& operator>>(File& in, type& variable)
{
    in.file << variable;
    return in.file;
};