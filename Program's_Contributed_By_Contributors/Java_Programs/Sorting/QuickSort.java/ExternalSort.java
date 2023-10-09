import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;

public class ExternalSort {
    public static void main(String[] args) {
        String inputFile = "large_input.txt"; // Change to your input file path
        String outputFile = "sorted_output.txt"; // Change to your output file path
        int chunkSize = 1000; // Number of elements to fit in memory

        externalSort(inputFile, outputFile, chunkSize);
    }

    public static void externalSort(String inputFile, String outputFile, int chunkSize) {
        try {
            // Read the input file in chunks, sort each chunk, and write to temporary files
            List<String> chunk = new ArrayList<>();
            List<String> tempFiles = new ArrayList<>();
            BufferedReader reader = new BufferedReader(new FileReader(inputFile));
            int lineCount = 0;
            String line;

            while ((line = reader.readLine()) != null) {
                chunk.add(line);
                lineCount++;

                if (lineCount == chunkSize) {
                    Collections.sort(chunk);
                    String tempFileName = "temp" + tempFiles.size() + ".txt";
                    writeChunkToFile(chunk, tempFileName);
                    tempFiles.add(tempFileName);
                    chunk.clear();
                    lineCount = 0;
                }
            }

            // Sort and write the remaining chunk (if any)
            if (!chunk.isEmpty()) {
                Collections.sort(chunk);
                String tempFileName = "temp" + tempFiles.size() + ".txt";
                writeChunkToFile(chunk, tempFileName);
                tempFiles.add(tempFileName);
            }

            reader.close();

            // Merge the sorted temporary files into the final output file
            mergeSortedFiles(tempFiles, outputFile);

            // Clean up temporary files
            for (String tempFile : tempFiles) {
                File file = new File(tempFile);
                file.delete();
            }

            System.out.println("External sorting completed.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void writeChunkToFile(List<String> chunk, String fileName) throws IOException {
        BufferedWriter writer = new BufferedWriter(new FileWriter(fileName));
        for (String line : chunk) {
            writer.write(line);
            writer.newLine();
        }
        writer.close();
    }

    private static void mergeSortedFiles(List<String> tempFiles, String outputFile) throws IOException {
        PriorityQueue<BufferedReader> queue = new PriorityQueue<>(
            (a, b) -> {
                try {
                    return a.readLine().compareTo(b.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                    return 0;
                }
            }
        );
        BufferedWriter writer = new BufferedWriter(new FileWriter(outputFile));

        // Open a reader for each temporary file and add to the priority queue
        for (String tempFile : tempFiles) {
            BufferedReader reader = new BufferedReader(new FileReader(tempFile));
            queue.add(reader);
        }

        // Merge the sorted lines from the temporary files
        String line;
        while (!queue.isEmpty()) {
            BufferedReader reader = queue.poll();
            line = reader.readLine();
            if (line != null) {
                writer.write(line);
                writer.newLine();
                queue.add(reader);
            }
        }

        writer.close();
    }
}
