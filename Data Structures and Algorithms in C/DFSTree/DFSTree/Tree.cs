using System;
using System.Collections.Generic;
using System.Text;
namespace DFSTree
{
    public class Tree<T> 
    {
        private readonly List<Tree<T>> privateChildren;
        public Tree(){ }//празен конструктор
        public Tree(T value)//конструктор, който приема само ст/ст за текущия "Node"
        {
            this.Value = value;
            this.Parent = null;//не се подава "родител"
            this.privateChildren = new List<Tree<T>>();
        }
        public Tree(T value/*root*/, params Tree<T>[] children)// конструктор, който приема "родител" и "децата му"
            : this(value)// извикваме горния конструктор
        {
            foreach (Tree<T> child in children)
            {
                child.Parent = this;//детето трябва да има "родител" и инстанцията, в която се намираме в момента ще е "родителя"
                this.privateChildren.Add(child);//добавяме "децата" в списъка
            }
        }
        public T Value { get; private set; } //стойност на текущия "node"(на конкретното кръгче,ако гледаме графично графа)
        public Tree<T> Parent { get; private set; } //референция за родителя
        public IReadOnlyCollection<Tree<T>> Children => this.privateChildren.AsReadOnly();//колекция(списък) с "децата"; "IReadOnlyCollection", за да може добавянето, премахването и т.н. да се извършва в самия клас чрез "private readonly List<Tree<T>> privateChildren;"
        public ICollection<T> OrderDepthFirstSearch()//метод за обхождане в дълбочина
        {
            var result = new List<T>();
            this.DepthFirstSearch(this/*root*/, result);//дъното на рекурсията ще е когато сме достигнали върха и там вече няма "деца" за обхождане
            return result;//връща резултата след обхождането на графа от тип List<T>;
        }
        private void DepthFirstSearch(Tree<T> subTree, List<T> result)//рекурсивен метод за обхождане в дълбочина
        {
            foreach (var child in subTree.Children)
            {
                this.DepthFirstSearch(child, result);//рекурсивно стигаме до дъното на графа
            }
            result.Add(subTree.Value);//добавяме елемента, който е бил на дъното,или последно посетения елемент от графа, или върха, който е останал
        }
        public void AddChild(T parent, Tree<T> child)//добавяме "дете" към даден"родител"
        {
            var parentSubtree = this.FindDepthFirstSearch(parent, this);//проверяваме дали "родителя" съществува
            if (this.CheckEmptyNode(parentSubtree))//проверява дали "родителя" не е "null"
            {
                parentSubtree.privateChildren.Add(child);//добавяме "дете" към списъка с деца на съответния "родител"
            } 
        }
        private Tree<T> FindDepthFirstSearch(T value, Tree<T> subtree)//метод   чрез който проверяваме дали "родителя" съществува
        {
            //обхождаме всяко дете от поддървото
            foreach (var child in subtree.Children)
            {
                Tree<T> current = this.FindDepthFirstSearch(value, child);//рекурсивно претърсване
                if (current != null&&current.Value.Equals(value))//ако "родителя" съществува и този "родител" е еднакъв с "родителя" подаден като параметър на метода
                {
                     return current;
                }
            }
            if (subtree.Value.Equals(value))
            {
                return subtree;//ако не сме намерили елемента, това означава, че "root" е търсения
            }
            return null;//изобщо нямаме такъв елемент в графа
        }
        private bool CheckEmptyNode(Tree<T> parentSubtree)//проверява дали "родителя" е "null"; ако метода  private Tree<T> FindDepthFirstSearch ни е върнал "null" ние тук се подсигуряваме да не хвърлим "Exception"
        {
            if (parentSubtree!=null)
            {
                return true;
            }
            return false;
        }
    }
}
