public class Person {
    private String ID;
    String name;
    String add;
    String Tel;
    String email;
    //两个设置函数
    void setID(String ID) {
        this.ID = ID;
    }

    void setName(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return "Person{" +
                "ID='" + ID + '\'' +
                ", name='" + name + '\'' +
                '}';
    }

}
