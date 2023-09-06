/*

Реализуйте многопоточную функцию вычисления произведения двух матриц. 
Функция должна высчитывать значения ячеек результативной матрицы в отдельном потоке для каждой строки.
Например, имея две матрицы 5x2 и 2x7 получается матрица 5x7. 
Должны быть запущены пять отдельных потоков для высчитывания каждой строки матрицы. 
Потоки запускать с помощью async.
*/

vector<vector<int>> multiply2(
    const vector<vector<int>>& matrix1,
    const vector<vector<int>>& matrix2)
{
    int final_lines_count = matrix1.size();
    int final_colums_count = matrix2[0].size();
    vector<vector<int>> result(final_lines_count);
    for (int i = 0; i < final_lines_count; i++) {
        result[i].resize(final_colums_count);
    }

    int common_size = matrix2.size();

    vector<future<void>> futures;
    for (int line_number = 0; line_number < final_lines_count; line_number++) {
        auto f = async(launch::async, [&, line_number]() {
            for (int i = 0; i < final_colums_count; i++) {
                int cell_result = 0;
                for (int j = 0; j < common_size; j++) {
                    cell_result += matrix1[line_number][j] * matrix2[j][i];
                }
                result[line_number][i] = cell_result;
            }
            });
        futures.push_back(std::move(f));
    }

    return result;
}