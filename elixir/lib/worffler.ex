defmodule Worffler do

  def start(in_file_1, in_file_2, out_file) do
    in2 = File.open!(in_file_2, [:read])
    out = File.open!(out_file, [:write])

    File.open!(in_file_1, [:read])
    |> IO.stream(:line)
    |> Stream.map(&String.rstrip(&1, ?\n))
    |> Stream.map(&write_entry(&1, in2, out))
    |> Stream.run
  end

  defp print(out, line1, line2) do
    IO.write out, line1 <> line2
  end

  defp write_entry(line, input, out) do
    IO.stream(input, :line)
    |> Stream.map(&print(out, line, &1))
    |> Stream.run

    #reset file pointer to the beginning of the file
    #because there is no elixir command for this, use erlang            
    {:ok, 0} = :file.position(input, :bof)
  end
end
