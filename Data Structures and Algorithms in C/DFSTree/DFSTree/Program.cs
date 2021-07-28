using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
namespace DFSTree
{
    class Program
    { 
        static void Main(string[] args)
        {
            StreamReader reader = new StreamReader("../../../input.txt");

            //обект от тип Tree<int>
            Tree<int> graph = new Tree<int>();

            //четене от файл
            using (reader)
            {
                while (true)
                {
                    string line = reader.ReadLine();
                    if (line == null)
                    {
                        break;
                    }
                    if (line == "END")
                    {
                        //извикване на метода за обхождане на графа
                        var traversedTree = graph.OrderDepthFirstSearch();

                        //писане във файл
                        using ( StreamWriter writer = new StreamWriter("../../../output.txt",true))
                        {
                            writer.Write("Graph: ");
                            foreach (var item in traversedTree)
                            {
                                writer.Write(item.ToString() + ", ");
                            }
                            writer.WriteLine();
                        }
                        continue;
                    }

                    //създаваме "родител" без "деца"
                    if (line.Contains("Root"))
                    {
                        var splited = line.Split(" ");
                        int root = int.Parse(splited[1]);
                        graph = new Tree<int>(root);
                    }
                    //щом получаваме тази команда сме сигурни, че вече има "родител", към който да добавим "дете"
                    else if (line.Contains("Add"))
                    {
                        var splited = line.Split(" ");
                        int root = int.Parse(splited[1]);
                        int child = int.Parse(splited[2]);
                        graph.AddChild(root, new Tree<int>(child));
                    }
                }
            }

        }

    }
}
