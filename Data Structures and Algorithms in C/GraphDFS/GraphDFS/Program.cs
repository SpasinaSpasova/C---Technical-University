using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;


namespace GraphDFS
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader reader = new StreamReader("../../../input.txt");
            Graph g = new Graph();//създаваме обект от тип "Graph"
            string line;
            using (reader)
            { 
               

                while (true)
                {
                    line = reader.ReadLine();// четем ред от файла
                    if (line == null)
                    {
                        break;//ако вече няма какво да четем във файла
                    }
                    if (line.Length==1|| line.Length == 2)//проверяваме дали броя на върховете на графа е едноцифрено или двуцифрено число
                    {
                        int n = int.Parse(line);
                        g = new Graph(n);//графа създаден по- горе го извикваме с друг конструктор, който заделя място в паметта за всеки един "n" на брой върха
                    }
                    if (line.Contains("END")) 
                    {
                        using (StreamWriter writer = new StreamWriter("../../../output.txt",true))
                        {
                            writer.Write("current: ");
                            var tokens = line.Split().ToArray();
                            var result= g.DFS(int.Parse(tokens[1]));

                            foreach (var item in result)//тъй като върнатия резултат от функцията за обхождане е лист ние трябва да минем през всеки един елемент и да го запишем във файла
                            {
                                writer.Write(item.ToString() + ", ");//записване във файл
                            }
                            writer.WriteLine();

                        }
                        continue;

                    }
                    if (line.Contains("Add"))
                    {
                        var splited = line.Split(" ");
                        int vertice = int.Parse(splited[1]);//връх
                        int verticeToAdd = int.Parse(splited[2]);//съсед, който трябва да се добави към листа на върха
                        g.Add(vertice, verticeToAdd);
                    }
                    
                }
            }
           
        }
    }
}