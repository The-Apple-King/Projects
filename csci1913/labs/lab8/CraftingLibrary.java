//Owen Swearingen
//lab 8
public class CraftingLibrary {

    private CraftingItem[] library = new CraftingItem[100];
    private int numItems = 0;

    public int getNumItems() {
        return numItems;
    }

    public String[] getItemNames() {
            String[] names = new String[numItems];
            for (int i = 0; i < numItems; i++) {
                names[i] = library[i].getName();
            }
            return names;
    }

    public boolean addItem(CraftingItem item1) {
        if (numItems < 100) {
            library[numItems] = item1;
            numItems++;
            return true;
        }
        return false;
    }

    public CraftingItem getItem(int i) {
        if (i >= 0 && i <= 100) {
            return library[i];
        }
        return null;
    }

    public double getcost(String name) {
        double cost = 0;
        for (int i = 0; i < numItems-1; i++) {
            if(library[i].getName().equals(name)){
                if (library[i].isBasicPart()) {
                    return library[i].getcost(); 
                }
                else{
                    for (int j = 0; j < library[i].getNumParts(); j++) {
                        cost += getcost(library[i].getPart(j));
                    }
                    return cost;
                }
            }
        }
        return cost;
    }

}
