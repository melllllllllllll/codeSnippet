import java.io.*;
import java.util.zip.*;

/**
* 代码可拓展, 使被压缩对象为一个文件、多个文件、文件和文件夹混合。
* 一种拓展思路是, 将所有被压缩对象(文件, 文件夹混合)整理到名为 dest(dest.zip) 的文件夹中, 然后一切照常进行。
* 当前程序在使用上, 可以牵强地用作通用压缩程序, 但每次需要将被压缩对象整理到一个文件。
*/

public class RecZip {
    private static final int BUFFER = 1024;

    public static void reczip(ZipOutputStream zout, File file, String absPath) throws IOException {
        int count;
        byte[] buffer = new byte[BUFFER];
        File[] fileItems = file.listFiles();
        for(File fileItem : fileItems) {
            if(fileItem.isDirectory()) {
                reczip(zout, fileItem, absPath + fileItem.getName() + File.separator);
            } else {
                zout.putNextEntry(new ZipEntry(absPath + fileItem.getName()));
                FileInputStream in = new FileInputStream(fileItem);
                while((count = in.read(buffer)) != -1) {
                    zout.write(buffer, 0, count);
                }
                zout.closeEntry();
                in.close();
            }
        }
    }
    
    public static void main(String[] args) throws IOException {
        // args[0] : dest.zip
        ZipOutputStream zout = new ZipOutputStream(new FileOutputStream(args[0]));
        // args[1] : dir to be compressed
        File file = new File(args[1]);
        reczip(zout, file, file.getName() + File.separator);
        zout.close();
    }
}
