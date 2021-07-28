using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GraphDFS
{

    public class Graph
    {
        private List<int>[] adjacency;//графа представлява масив от листове на съседство
        public int Vertices { get; private set; } // брой на върховете
        public Graph() { }//празен конструктор, нужен ни е за първото създаване на обект от тип "Graph"
        public Graph(int vertices)//3ти конструктор, който приема броя на върховете в един граф
        {
            this.Vertices = vertices;
            adjacency = new List<int>[Vertices];//създаване на масив от листове на съседство с размер броя на върховете

            for (int i = 0; i < Vertices; ++i)
            {
                adjacency[i] = new List<int>();// всеки връх на графа, ще има собствен лист на съседство 
            }
        }
        public void Add(int vertices, int verticesToAdd)//добавяме наследник на конкретен връх
        {
            adjacency[vertices].Add(verticesToAdd);
        }
        public List<int> DFS(int v)// метод за обхождане в дълбочина на граф, от конкретен връх
        {  
            bool[] discovered = new bool[Vertices];//маркираме всички върхове на графа, като непосетени

            Stack<int> stack = new Stack<int>();//създаваме стек, в който ще записваме всеки един посетен връх
            List<int> res = new List<int>();// създаваме лист, в който ще добавяме всеки един обходен връх и ще се връща като резултат от фунцкията и съответно ще бъде записан във файла

            discovered[v] = true;//маркираме подадения връх на функцията като посетен
            stack.Push(v);//добавяме го в стека
            while (stack.Count != 0)//докато в стека има върхове ще се изпълнява цикъла
            {
                v = stack.Pop();//взимаме последно сложения връх в стека

                res.Add(v);//записваме в листа последния връх, който сме взели от стека

                foreach (var item in adjacency[v])// започваме да обхождаме листа на съседство на конкретния връх
                {
                    if (!discovered[item])//ако даден предщественик не е маркиран като посетен, ние го маркираме като такъв и го слагамае най- отгоре в стека; и така докато не обходим всеки един връх с неговите наследници
                    {
                        discovered[item] = true;
                        stack.Push(item);//довавяме в стека
                    }
                }


            }

            return res;// връщаме резултата от обхождането
        }

    }



}


