function A = image_extend_30(B);

A = zeros(510,660);
for i = 1 : 450
    for j = 1 : 600
    A(i + 30,j + 30) = B(i,j);
    end
end

for i = 1 : 30
    for j = 1 : 600
    A(i,j + 30) = B(i,j);
    end
end

for i =  480: 510
    for j = 1 : 600
    A(i,j + 30) = B(i - 60,j);
    end
end

for j = 1 : 30
    for i = 1 : 450
    A(i + 30,j) = B(i,j);
    end
end

for j = 630 : 660
    for i = 1 : 450
    A(i + 30,j) = B(i,j - 60);
    end
end

for i = 1 : 30
    for j = 1 : 30
    A(i,j) = A(i, j + 30);
    end
end

for i = 1 : 30
    for j = 630 : 660
    A(i,j) = A(i, j - 30);
    end
end

for i = 480 : 510
    for j = 1 : 30
    A(i,j) = A(i, j + 30);
    end
end

for i = 480 : 510
    for j = 630 : 660
    A(i,j) = A(i, j - 30);
    end
end

end
