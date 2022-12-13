module com.example.demofxxxxx {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.controlsfx.controls;
    requires org.kordamp.bootstrapfx.core;

    opens com.example.demofxxxxx to javafx.fxml;
    exports com.example.demofxxxxx;
}