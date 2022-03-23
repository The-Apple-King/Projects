//Owen Swearingen
//lab 8
public class CraftingItem {
    private String name;
    private double cost;
    private String[] formula;

    public CraftingItem(String itemName, String[] itemFormula) {
        name = itemName;
        formula = itemFormula;
    }

    public CraftingItem(String itemName, double itemCost) {
        name = itemName;
        cost = itemCost;
    }

    public String getName() {
        return name;
    }

    public boolean isRecipe() {
        return (formula != null);
    }

    public double getcost() {
        return cost;
    }

    public int getNumParts() {
        if (formula == null) {
            return 0;
        } else {
            return formula.length;
        }
    }

    public String getPart(int i) {
        if (formula == null || formula.length - 1 < i || i < 0) {
            return null;
        } else {
            return formula[i];
        }
    }

    public String toString() {
        return "name: " + name + ", cost: " + cost + ", parts: " + java.util.Arrays.toString(formula);
    }

    public boolean isBasicPart() {
        return (formula == null);
    }

    public boolean equals(CraftingItem item2){
        return (this.toString().equals(item2.toString()));
    }
}
