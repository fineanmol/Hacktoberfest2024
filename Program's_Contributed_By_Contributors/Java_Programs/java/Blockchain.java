public class Block {
    private String hash;
    private String previousHash;
    private String data;
    private long timeStamp;
    private int nonce;
 
    public Block(String data, String previousHash, long timeStamp) {
        this.data = data;
        this.previousHash = previousHash;
        this.timeStamp = timeStamp;
        this.hash = calculateBlockHash();
    }
    // standard getters and setters
}
