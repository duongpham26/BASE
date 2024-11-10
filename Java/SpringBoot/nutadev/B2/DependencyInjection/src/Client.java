public class Client implements InjectionInterface {
    private MessageInterface messageInterface;

    public Client() {};

    // inject through constructor
    public Client(MessageInterface messageInterface) {
        this.messageInterface = messageInterface;
    }

    // inject through setter
    public void setMessageInterface(MessageInterface messageInterface) {
        this.messageInterface = messageInterface;
    }

    // inject through interface
    @Override
    public void inject(MessageInterface messageInterface) {
        this.messageInterface = messageInterface;
    }

    public void processMessage(String message) {
        messageInterface.sendMessage(message);
    }

}
