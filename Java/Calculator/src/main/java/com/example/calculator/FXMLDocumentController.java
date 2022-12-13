package com.example.calculator;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.TextField;

public class FXMLDocumentController {
@FXML
 private TextField tfNumber1, tfNumber2, tfNumber3;

 @FXML
private void addButtonAction(ActionEvent event) {
     tfNumber3.setText(getResult('+') + "");
         }

        @FXML
 private void subtractButtonAction(ActionEvent event) {
            tfNumber3.setText(getResult('−') + "");
         }

         @FXML
 private void multiplyButtonAction(ActionEvent event) {
             tfNumber3.setText(getResult('*') + "");
         }

         @FXML
private void divideButtonAction(ActionEvent event) {
             tfNumber3.setText(getResult('/') + "");
         }

         private double getResult(char op) {
        double number1 = Double.parseDouble(tfNumber1.getText());
         double number2 = Double.parseDouble(tfNumber2.getText());
       switch (op) {
            case '+': return number1 + number2;
            case '−': return number1 - number2;
             case '*': return number1 * number2;
            case '/': return number1 / number2;
             }
         return Double.NaN;
         }
 }