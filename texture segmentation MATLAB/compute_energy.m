function A = compute_energy(B,ext);

A = zeros(450,600);

for i = ext+1 : (450 + ext)
    for j = ext+1 : (600 + ext)
        sum = 0.0;
        for i1 = -(ext) : ext
            for j1 = -(ext) : ext
            
                sum = sum + (B(i1 + i, j1 + j))^2;
            end
        end
        sum = sum / (121 * 121);
        %sum = sum * sum;
        A(i - ext,j - ext) = sum;
    end
end
end
