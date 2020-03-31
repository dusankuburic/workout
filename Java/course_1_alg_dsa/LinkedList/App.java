public class App {
    public static void main(String[] args) {
        
        List<Person> list = new LinkedList<Person>();
        
        Person p = new Person(22,"Adam");
        
        list.insert(p);
        list.insert(new Person(19,"Kevin"));
        list.insert(new Person(45,"Joe"));
        list.insert(new Person(32,"Michael"));
        
        System.out.println(list.size());
        
        list.remove(p);
        
        list.traverseList();
        
    }
}
