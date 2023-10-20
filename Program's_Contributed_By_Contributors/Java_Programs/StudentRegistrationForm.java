import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
 
public class StudentRegistrationForm extends JFrame {
   private JTextField nameField, emailField;
   private JComboBox<String> genderComboBox;
   private JCheckBox javaCheckBox, pythonCheckBox, cppCheckBox;
 
   public StudentRegistrationForm() {
       setTitle("Student Registration Form");
       setSize(400, 300);
       setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
       setLocationRelativeTo(null);
 
       JPanel panel = new JPanel();
       panel.setLayout(new GridLayout(6, 2, 10, 10));
 
       JLabel nameLabel = new JLabel("Name:");
       nameField = new JTextField(20);
 
       JLabel emailLabel = new JLabel("Email:");
       emailField = new JTextField(20);
 
       JLabel genderLabel = new JLabel("Gender:");
       String[] genders = {"Male", "Female", "Other"};
       genderComboBox = new JComboBox<>(genders);
 
       JLabel skillsLabel = new JLabel("Programming Skills:");
       javaCheckBox = new JCheckBox("Java");
       pythonCheckBox = new JCheckBox("Python");
       cppCheckBox = new JCheckBox("C++");
 
       JButton submitButton = new JButton("Submit");
       submitButton.addActionListener(new ActionListener() {
           public void actionPerformed(ActionEvent e) {
               StringBuilder result = new StringBuilder("Registration Details:\n");
               result.append("Name: ").append(nameField.getText()).append("\n");
               result.append("Email: ").append(emailField.getText()).append("\n");
               result.append("Gender: ").append(genderComboBox.getSelectedItem()).append("\n");
               result.append("Programming Skills: ");
               if (javaCheckBox.isSelected()) {
                   result.append("Java ");
               }
               if (pythonCheckBox.isSelected()) {
                   result.append("Python ");
               }
               if (cppCheckBox.isSelected()) {
                   result.append("C++");
               }
               JOptionPane.showMessageDialog(null, result.toString(), "Registration Successful", JOptionPane.INFORMATION_MESSAGE);
           }
       });
 
       
panel.add(nameLabel);
       panel.add(nameField);
       panel.add(emailLabel);
       panel.add(emailField);
       panel.add(genderLabel);
       panel.add(genderComboBox);
       panel.add(skillsLabel);
       panel.add(javaCheckBox);
       panel.add(pythonCheckBox);
       panel.add(cppCheckBox);
       panel.add(new JLabel());
       panel.add(submitButton);
       add(panel);
   }
 
   public static void main(String[] args) {
       SwingUtilities.invokeLater(() -> {
           StudentRegistrationForm form = new StudentRegistrationForm();
           form.setVisible(true);
       });
   }
}
