
def min_e_seam_t(lis_e):
    col_total = len(lis_e[0])
    row_total = len(lis_e)
    sum = 0
    min_e = 1000
    saved_col_ind = 0

    #first row to find starting point
    for col_ind in range(col_total):
        if lis_e[0][col_ind] < min_e:
            min_e = lis_e[0][col_ind]
            saved_col_ind = col_ind
    sum += min_e

    #rest of the rows
    for row_ind in range(1, row_total):

        #direct bottom start as min
        col_ind = saved_col_ind
        min_e = lis_e[row_ind][col_ind]

        #left bottom
        if lis_e[row_ind][col_ind - 1] < min_e:
            min_e = lis_e[row_ind][col_ind - 1]
            saved_col_ind = col_ind - 1;

        #right bottom
        if lis_e[row_ind][col_ind + 1] < min_e:
            min_e = lis_e[row_ind][col_ind + 1]
            saved_col_ind = col_ind + 1;

        sum += min_e

    return sum

def min_e_seam_b(lis_e):
    col_total = len(lis_e[0])
    row_total = len(lis_e)
    sum = 0
    min_e = 1000
    saved_col_ind = 0

    #last row to find starting point
    for col_ind in range(col_total):
        if lis_e[row_total - 1][col_ind] < min_e:
            min_e = lis_e[row_total - 1][col_ind]
            saved_col_ind = col_ind
    sum += min_e

    #rest of the rows
    for i in range(2, row_total + 1):

        row_ind = row_total - i
        #direct top start as min
        col_ind = saved_col_ind
        min_e = lis_e[row_ind][col_ind]

        #left top
        if col_ind > 0:
            if lis_e[row_ind][col_ind - 1] < min_e:
                min_e = lis_e[row_ind][col_ind - 1]
                saved_col_ind = col_ind - 1

        #right top
        if lis_e[row_ind][col_ind + 1] < min_e:
            min_e = lis_e[row_ind][col_ind + 1]
            saved_col_ind = col_ind + 1

        #print(min_e)
        sum += min_e

    return sum

energies = [[24, 22, 30, 15, 18, 19],
            [12, 23, 15, 23, 10, 15],
            [11, 13, 22, 13, 21, 14],
            [13, 15, 17, 28, 19, 21],
            [17, 17,  7, 27, 20, 19]]

seam = min_e_seam_t(energies)
print("min_e_seam_t:", seam)
seam = min_e_seam_b(energies)
print("min_e_seam_b:", seam)


