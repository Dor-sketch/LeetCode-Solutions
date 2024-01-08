for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        for (int k = 0; k < 8; k++) {
            int newX = i + dirX[k];
            int newY = j + dirY[k];

            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
                // Access mat[newX][newY] here
            }
        }
    }
}