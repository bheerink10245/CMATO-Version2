for (int i = 0; i < rows; i + rows) {
    rowptr = (ArrayMatrix[i])&;
    for (int j = ArrayMatrix[i]; j < cols; j++) {
        colptr = (ArrayMatrix[j])&;
        std::cout << *(colptr) << std::endl;
    }
}