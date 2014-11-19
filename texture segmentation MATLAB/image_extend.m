function A = image_extend(B);

A = zeros(452,602);
for i = 1 : 450
    for j = 1 : 600
    A(i + 1,j + 1) = B(i,j);
    end
end

for i = 1 : 1
    for j = 1 : 600
    A(i,j + 1) = B(i,j);
    end
end

for i =  452: 452
    for j = 1 : 600
    A(i,j + 1) = B(i - 2,j);
    end
end

for j = 1 : 1
    for i = 1 : 450
    A(i + 1,j) = B(i,j);
    end
end

for j = 602 : 602
    for i = 1 : 450
    A(i + 1,j) = B(i,j - 2);
    end
end

A(1,1) = A(1,3);
A(1,602) = A(1,601);
A(452,1) = A(452,2);
A(452,602) = A(452,601);

end
