function A = image_extend_15(B);

A = zeros(480,630);
for i = 1 : 450
    for j = 1 : 600
    A(i + 15,j + 15) = B(i,j);
    end
end

for i = 1 : 15
    for j = 1 : 600
    A(i,j + 15) = B(i,j);
    end
end

for i =  466: 480
    for j = 1 : 600
    A(i,j + 15) = B(i - 30,j);
    end
end

for j = 1 : 15
    for i = 1 : 450
    A(i + 15,j) = B(i,j);
    end
end

for j = 616 : 630
    for i = 1 : 450
    A(i + 15,j) = B(i,j - 30);
    end
end

for i = 1 : 15
    for j = 1 : 15
    A(i,j) = A(i, j + 15);
    end
end

for i = 1 : 15
    for j = 616 : 630
    A(i,j) = A(i, j - 15);
    end
end

for i = 466 : 480
    for j = 1 : 15
    A(i,j) = A(i, j + 15);
    end
end

for i = 466 : 480
    for j = 616 : 630
    A(i,j) = A(i, j - 15);
    end
end

end
