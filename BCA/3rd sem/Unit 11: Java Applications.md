### Unit 11: Java Applications [8 Hrs.]

In this unit, we will explore Java's graphical user interface (GUI) programming using **AWT** and **Swing**. We will learn about Swing components, event handling, layout management, and advanced features like menus, dialog boxes, and tables. Additionally, we will discuss how to use Integrated Development Environments (IDEs) like NetBeans for building Java applications.

---

### 1. About AWT & Swing

**AWT (Abstract Window Toolkit)**:  
AWT is Java's original GUI framework. It provides basic components like buttons, labels, and text fields but relies on the native operating system's GUI components, making it platform-dependent.

**Swing**:  
Swing is an extension of AWT and is part of the Java Foundation Classes (JFC). It provides a richer set of components that are entirely written in Java, making them platform-independent. Swing components are lightweight and more flexible than AWT.

---

### 2. JFrame (Top-Level Window in Swing)

**Definition**:  
`JFrame` is a top-level container in Swing used to create windows. It provides a framework for adding other Swing components like buttons, labels, and text fields.

**Program Example**:
```java
import javax.swing.*;

public class JFrameExample {
    public static void main(String[] args) {
        // Create a JFrame
        JFrame frame = new JFrame("My First Swing Application");
        frame.setSize(400, 300); // Set size
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // Close operation
        frame.setVisible(true); // Make the frame visible
    }
}
```

**Explanation**:  
- We create a `JFrame` object and set its title, size, and close operation.
- The `setVisible(true)` method makes the frame visible on the screen.

**Sample Output**:  
A window titled "My First Swing Application" with a size of 400x300 pixels.

---

### 3. Swing Components

#### a. **JLabel**
**Definition**:  
`JLabel` is used to display a short string or an image on the screen.

**Program Example**:
```java
import javax.swing.*;

public class JLabelExample {
    public static void main(String[] args) {
        JFrame frame = new JFrame("JLabel Example");
        JLabel label = new JLabel("Hello, Swing!"); // Create a JLabel
        frame.add(label); // Add label to the frame
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
```

**Explanation**:  
- We create a `JLabel` with the text "Hello, Swing!" and add it to the `JFrame`.

**Sample Output**:  
A window displaying the text "Hello, Swing!".

---

#### b. **JTextField**
**Definition**:  
`JTextField` is a text component that allows the user to enter a single line of text.

**Program Example**:
```java
import javax.swing.*;

public class JTextFieldExample {
    public static void main(String[] args) {
        JFrame frame = new JFrame("JTextField Example");
        JTextField textField = new JTextField("Enter text here"); // Create a JTextField
        frame.add(textField); // Add text field to the frame
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
```

**Explanation**:  
- We create a `JTextField` with default text and add it to the `JFrame`.

**Sample Output**:  
A window with a text field containing the text "Enter text here".

---

#### c. **JButton**
**Definition**:  
`JButton` is a component that triggers an action when clicked.

**Program Example**:
```java
import javax.swing.*;

public class JButtonExample {
    public static void main(String[] args) {
        JFrame frame = new JFrame("JButton Example");
        JButton button = new JButton("Click Me"); // Create a JButton
        frame.add(button); // Add button to the frame
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
```

**Explanation**:  
- We create a `JButton` with the label "Click Me" and add it to the `JFrame`.

**Sample Output**:  
A window with a button labeled "Click Me".

---

### 4. Event Handling in Swing Applications

**Definition**:  
Event handling is the mechanism to handle user interactions like button clicks, mouse movements, or key presses.

**Program Example**:
```java
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class EventHandlingExample {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Event Handling Example");
        JButton button = new JButton("Click Me");
        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(frame, "Button Clicked!");
            }
        });
        frame.add(button);
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
```

**Explanation**:  
- We add an `ActionListener` to the `JButton` to handle button click events.
- When the button is clicked, a dialog box displays the message "Button Clicked!".

**Sample Output**:  
A window with a button. Clicking the button shows a dialog box with the message "Button Clicked!".

---

### 5. Layout Management

#### a. **FlowLayout**
**Definition**:  
`FlowLayout` arranges components in a row, one after the other.

**Program Example**:
```java
import javax.swing.*;
import java.awt.FlowLayout;

public class FlowLayoutExample {
    public static void main(String[] args) {
        JFrame frame = new JFrame("FlowLayout Example");
        frame.setLayout(new FlowLayout()); // Set FlowLayout
        frame.add(new JButton("Button 1"));
        frame.add(new JButton("Button 2"));
        frame.add(new JButton("Button 3"));
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
```

**Explanation**:  
- We set the layout of the `JFrame` to `FlowLayout` and add three buttons.

**Sample Output**:  
A window with three buttons arranged in a row.

---

#### b. **BorderLayout**
**Definition**:  
`BorderLayout` divides the container into five regions: North, South, East, West, and Center.

**Program Example**:
```java
import javax.swing.*;
import java.awt.BorderLayout;

public class BorderLayoutExample {
    public static void main(String[] args) {
        JFrame frame = new JFrame("BorderLayout Example");
        frame.setLayout(new BorderLayout()); // Set BorderLayout
        frame.add(new JButton("North"), BorderLayout.NORTH);
        frame.add(new JButton("South"), BorderLayout.SOUTH);
        frame.add(new JButton("East"), BorderLayout.EAST);
        frame.add(new JButton("West"), BorderLayout.WEST);
        frame.add(new JButton("Center"), BorderLayout.CENTER);
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
```

**Explanation**:  
- We add buttons to the five regions of the `BorderLayout`.

**Sample Output**:  
A window with buttons placed in the North, South, East, West, and Center regions.

---

#### c. **GridLayout**
**Definition**:  
`GridLayout` arranges components in a grid of rows and columns.

**Program Example**:
```java
import javax.swing.*;
import java.awt.GridLayout;

public class GridLayoutExample {
    public static void main(String[] args) {
        JFrame frame = new JFrame("GridLayout Example");
        frame.setLayout(new GridLayout(2, 3)); // Set GridLayout with 2 rows and 3 columns
        frame.add(new JButton("Button 1"));
        frame.add(new JButton("Button 2"));
        frame.add(new JButton("Button 3"));
        frame.add(new JButton("Button 4"));
        frame.add(new JButton("Button 5"));
        frame.add(new JButton("Button 6"));
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
```

**Explanation**:  
- We set the layout to `GridLayout` with 2 rows and 3 columns and add six buttons.

**Sample Output**:  
A window with six buttons arranged in a 2x3 grid.

---

### 6. Advanced Swing Components

#### a. **JCheckBox**
**Definition**:  
`JCheckBox` is a component that allows the user to select or deselect an option.

**Program Example**:
```java
import javax.swing.*;

public class JCheckBoxExample {
    public static void main(String[] args) {
        JFrame frame = new JFrame("JCheckBox Example");
        JCheckBox checkBox = new JCheckBox("Enable Feature"); // Create a JCheckBox
        frame.add(checkBox); // Add checkbox to the frame
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
```

**Explanation**:  
- We create a `JCheckBox` with the label "Enable Feature" and add it to the `JFrame`.

**Sample Output**:  
A window with a checkbox labeled "Enable Feature".

---

#### b. **JRadioButton**
**Definition**:  
`JRadioButton` is used to create a group of mutually exclusive options.

**Program Example**:
```java
import javax.swing.*;

public class JRadioButtonExample {
    public static void main(String[] args) {
        JFrame frame = new JFrame("JRadioButton Example");
        JRadioButton radio1 = new JRadioButton("Option 1");
        JRadioButton radio2 = new JRadioButton("Option 2");
        ButtonGroup group = new ButtonGroup(); // Create a ButtonGroup
        group.add(radio1);
        group.add(radio2);
        frame.add(radio1);
        frame.add(radio2);
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
```

**Explanation**:  
- We create two `JRadioButton` objects and add them to a `ButtonGroup` to ensure mutual exclusivity.

**Sample Output**:  
A window with two radio buttons labeled "Option 1" and "Option 2".

---

#### c. **JComboBox**
**Definition**:  
`JComboBox` is a drop-down list that allows the user to select one option from a list.

**Program Example**:
```java
import javax.swing.*;

public class JComboBoxExample {
    public static void main(String[] args) {
        JFrame frame = new JFrame("JComboBox Example");
        String[] options = {"Option 1", "Option 2", "Option 3"};
        JComboBox<String> comboBox = new JComboBox<>(options); // Create a JComboBox
        frame.add(comboBox); // Add combo box to the frame
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
```

**Explanation**:  
- We create a `JComboBox` with three options and add it to the `JFrame`.

**Sample Output**:  
A window with a drop-down list containing "Option 1", "Option 2", and "Option 3".

---

#### d. **JList**
**Definition**:  
`JList` is a component that displays a list of items from which the user can select one or more items.

**Program Example**:
```java
import javax.swing.*;

public class JListExample {
    public static void main(String[] args) {
        JFrame frame = new JFrame("JList Example");
        String[] items = {"Item 1", "Item 2", "Item 3"};
        JList<String> list = new JList<>(items); // Create a JList
        frame.add(new JScrollPane(list)); // Add JList to a JScrollPane
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
```

**Explanation**:  
- We create a `JList` with three items and add it to a `JScrollPane` for scrolling.

**Sample Output**:  
A window with a list containing "Item 1", "Item 2", and "Item 3".

---

### 7. Key & Mouse Event Handling

**Definition**:  
Key and mouse events are used to handle user interactions like key presses and mouse clicks.

**Program Example**:
```java
import javax.swing.*;
import java.awt.event.*;

public class KeyMouseEventExample {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Key & Mouse Event Example");
        JTextField textField = new JTextField();
        textField.addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                System.out.println("Key Pressed: " + e.getKeyChar());
            }
        });
        frame.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                System.out.println("Mouse Clicked at: " + e.getX() + ", " + e.getY());
            }
        });
        frame.add(textField);
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
```

**Explanation**:  
- We add a `KeyListener` to handle key presses and a `MouseListener` to handle mouse clicks.

**Sample Output**:  
- When a key is pressed, the key character is printed.
- When the mouse is clicked, the coordinates of the click are printed.

---

### 8. Menus in Swing

**Definition**:  
Menus are used to create dropdown menus in Swing applications.

**Program Example**:
```java
import javax.swing.*;

public class MenuExample {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Menu Example");
        JMenuBar menuBar = new JMenuBar(); // Create a menu bar
        JMenu fileMenu = new JMenu("File"); // Create a menu
        JMenuItem openItem = new JMenuItem("Open"); // Create a menu item
        fileMenu.add(openItem);
        menuBar.add(fileMenu);
        frame.setJMenuBar(menuBar); // Add menu bar to the frame
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
```

**Explanation**:  
- We create a `JMenuBar`, add a `JMenu` to it, and add a `JMenuItem` to the menu.

**Sample Output**:  
A window with a "File" menu containing an "Open" option.

---

### 9. Dialog Boxes in Swing

**Definition**:  
Dialog boxes are used to display messages or prompt the user for input.

**Program Example**:
```java
import javax.swing.*;

public class DialogBoxExample {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Dialog Box Example");
        JOptionPane.showMessageDialog(frame, "This is a message dialog!");
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
```

**Explanation**:  
- We use `JOptionPane.showMessageDialog` to display a message dialog.

**Sample Output**:  
A dialog box with the message "This is a message dialog!".

---

### 10. JTable for Displaying Data in Tabular Form

**Definition**:  
`JTable` is used to display data in a tabular format.

**Program Example**:
```java
import javax.swing.*;

public class JTableExample {
    public static void main(String[] args) {
        JFrame frame = new JFrame("JTable Example");
        String[][] data = {{"1", "John", "Doe"}, {"2", "Jane", "Doe"}};
        String[] columns = {"ID", "First Name", "Last Name"};
        JTable table = new JTable(data, columns); // Create a JTable
        frame.add(new JScrollPane(table)); // Add JTable to a JScrollPane
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
```

**Explanation**:  
- We create a `JTable` with data and column names and add it to a `JScrollPane`.

**Sample Output**:  
A window with a table displaying the data.

---

### 11. MDI Using JDesktopPane & JInternalFrame

**Definition**:  
MDI (Multiple Document Interface) allows multiple windows to be displayed within a single parent window.

**Program Example**:
```java
import javax.swing.*;

public class MDIExample {
    public static void main(String[] args) {
        JFrame frame = new JFrame("MDI Example");
        JDesktopPane desktopPane = new JDesktopPane(); // Create a JDesktopPane
        JInternalFrame internalFrame = new JInternalFrame("Internal Frame", true, true, true, true);
        internalFrame.setSize(200, 150);
        internalFrame.setVisible(true);
        desktopPane.add(internalFrame);
        frame.add(desktopPane);
        frame.setSize(400, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
```

**Explanation**:  
- We create a `JDesktopPane` and add a `JInternalFrame` to it.

**Sample Output**:  
A window with an internal frame inside it.

---

### 12. Using IDE like NetBeans

**Definition**:  
IDEs like NetBeans provide drag-and-drop functionality for building Java applications quickly.

**Steps**:  
1. Open NetBeans and create a new Java Application.
2. Use the GUI Builder to drag and drop components like buttons, labels, and text fields.
3. Write event-handling code in the generated methods.

---

### 13. Adapter Classes

**Definition**:  
Adapter classes provide default implementations for event listener interfaces, reducing the need to implement all methods.

**Example**:  
- `MouseAdapter` provides default implementations for `MouseListener` methods.

---

### Summary

In this unit, we
