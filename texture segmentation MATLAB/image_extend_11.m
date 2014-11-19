function A = image_extend_11(B);

A = zeros(472,622);
for i = 1 : 450
    for j = 1 : 600
    A(i + 11,j + 11) = B(i,j);
    end
end

for i = 1 : 11
    for j = 1 : 600
    A(i,j + 11) = B(i,j);
    end
end

for i =  461: 472
    for j = 1 : 600
    A(i,j + 11) = B(i - 22,j);
    end
end

for j = 1 : 11
    for i = 1 : 450
    A(i + 11,j) = B(i,j);
    end
end

for j = 611 : 622
    for i = 1 : 450
    A(i + 11,j) = B(i,j - 22);
    end
end

for i = 1 : 11
    for j = 1 : 11
    A(i,j) = A(i, j + 11);
    end
end

for i = 1 : 11
    for j = 611 : 622
    A(i,j) = A(i, j - 11);
    end
end

for i = 461 : 472
    for j = 1 : 11
    A(i,j) = A(i, j + 11);
    end
end

for i = 461 : 472
    for j = 611 : 622
    A(i,j) = A(i, j - 11);
    end
end

end
